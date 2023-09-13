// CRank.cpp: 实现文件
//

#include "pch.h"
#include "TikSEU.h"
#include "afxdialogex.h"
#include "CRank.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheets.h"
#include "CWorksheet.h"
#include "afxcmn.h"
#include <Shlwapi.h>
#include "afxdb.h"
#include "CApplication.h"
#include "CRange.h"
#include "TikSEUDlg.h"

// CRank 对话框

IMPLEMENT_DYNAMIC(CRank, CDialogEx)

CRank::CRank(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Rank, pParent)
{
	NewScore=0;
	FromParent = 0;
}

CRank::CRank(CString id, int score, CWnd* pParent /*=nullptr*/) {
	NewScore = 0;
	FromParent = 1;
	NewID = id;
	NewScore = score;
}

CRank::~CRank()
{
}

void CRank::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_programLangList);
}


BEGIN_MESSAGE_MAP(CRank, CDialogEx)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CRank 消息处理程序

void CRank::ReadAllItem(CString sExcelFile) // 读取Excel文本
{
	CApplication App;//创建应用实例
	CWorkbooks Books;//工作簿，多个Excel文件
	CWorkbook Book;//单个工作簿
	CWorksheets sheets;//多个sheets页面
	CWorksheet sheet;//单个sheet页面
	CRange range;//操作单元格
	CRange iCell;
	LPDISPATCH lpDisp;
	COleVariant vResult;  //COleVariant类是对VARIANT结构的封装
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	bool ifBigFish=1;


	if (!App.CreateDispatch(_T("Excel.Application"), NULL))
	{
		AfxMessageBox(_T("无法启动Excel服务器!"));
		return;
	}


	Books.AttachDispatch(App.get_Workbooks());
	lpDisp = Books.Open(sExcelFile, covOptional, covOptional,
		covOptional, covOptional, covOptional, covOptional, covOptional,
		covOptional, covOptional, covOptional, covOptional, covOptional,
		covOptional, covOptional);


	//得到Workbook    
	Book.AttachDispatch(lpDisp);
	//得到Worksheets   
	sheets.AttachDispatch(Book.get_Worksheets());
	//得到当前活跃sheet 
	//如果有单元格正处于编辑状态中，此操作不能返回，会一直等待 
	lpDisp = Book.get_ActiveSheet();
	sheet.AttachDispatch(lpDisp);

	//获取行列号
	range = sheet.get_UsedRange();
	range = range.get_Rows();
	long rows = range.get_Count();
	range = range.get_Columns();
	long columns = range.get_Count();

	// 清空List数据
	m_programLangList.DeleteAllItems(); //清空所有表项

	// 设置Id的值
	CString strSql = _T("select * from UserInfo;");

	CString strLastId;

	m_rows = 20;
	int lastId = RowToId[m_rows - 1] + 1;
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_programLangList.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_programLangList.SetExtendedStyle(m_programLangList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_programLangList.InsertColumn(0, _T("排名"), LVCFMT_CENTER, rect.Width() / 5, 0);
	m_programLangList.InsertColumn(1, _T("玩家"), LVCFMT_CENTER, 2* rect.Width() / 5, 1);
	m_programLangList.InsertColumn(2, _T("分数"), LVCFMT_CENTER, 2* rect.Width() / 5, 2);

	for (long i = 2; i < rows + 1; i++) // 从第二行开始读数据，第一行是表头的信息
	{
		CStringArray strListData; // 存储放在List中的Data信息

		for (long j = 1; j < columns + 1; j++)
		{
			range.AttachDispatch(sheet.get_Cells());
			range.AttachDispatch(range.get_Item(COleVariant(i), COleVariant((long)j)).pdispVal);   //第一变量是行，第二个变量是列，即第i行第j列
			vResult = range.get_Value2();
			CString str;
			if (vResult.vt == VT_BSTR) //字符串  
			{
				str = vResult.bstrVal;
				strListData.Add(str);
			}
			else if (vResult.vt == VT_R8) //8字节的数字  
			{
				str.Format(_T("%.lf"), vResult.dblVal);
				strListData.Add(str);
			}
			else // 若Excel有个单元格为空时会出现错误
			{
				strListData.Add(_T(""));
			}
		}
		CString Ranking;
		if (FromParent) {
			if (ifBigFish) {
				int OldScore = _ttoi(strListData[2]);
				Ranking.Format(L"%d", i - 1);
				if (NewScore >= OldScore) {
					CString NewScoreStr;
					NewScoreStr.Format(L"%d", NewScore);
					m_programLangList.InsertItem(i - 2, Ranking);
					m_programLangList.SetItemText(i - 2, 1, NewID);
					m_programLangList.SetItemText(i - 2, 2, NewScoreStr);
					ifBigFish = 0;
				}
				else {
					m_programLangList.InsertItem(i - 2, Ranking);
					m_programLangList.SetItemText(i - 2, 1, strListData[1]);
					m_programLangList.SetItemText(i - 2, 2, strListData[2]);
				}
			}
			if (!ifBigFish) {
				Ranking.Format(L"%d", i);
				m_programLangList.InsertItem(i - 1, Ranking);
				m_programLangList.SetItemText(i - 1, 1, strListData[1]);
				m_programLangList.SetItemText(i - 1, 2, strListData[2]);
			}
		}
		else {
			Ranking.Format(L"%d", i - 1);
			m_programLangList.InsertItem(i - 2, Ranking);
			m_programLangList.SetItemText(i - 2, 1, strListData[1]);
			m_programLangList.SetItemText(i - 2, 2, strListData[2]);
		}
	}
	if (ifBigFish && FromParent) {
		CString NewScoreStr;
		CString Ranking;
		NewScoreStr.Format(L"%d", NewScore);
		Ranking.Format(L"%d", rows);
		m_programLangList.InsertItem(rows-1, Ranking);
		m_programLangList.SetItemText(rows-1, 1, NewID);
		m_programLangList.SetItemText(rows-1, 2, NewScoreStr);
	}


	Books.Close();
	App.Quit();
	//释放对象      
	range.ReleaseDispatch();
	sheet.ReleaseDispatch();
	sheets.ReleaseDispatch();
	Book.ReleaseDispatch();
	Books.ReleaseDispatch();
	App.ReleaseDispatch();
}

BOOL CRank::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString sExcelFile;
	sExcelFile = GetModuleDir() + _T("res\\Rankings.xlsx");
	//global::TikSEU.Properties.Resources.Rankings;
	ReadAllItem(sExcelFile);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString CRank::GetModuleDir() {
	//CString szFile(_T(""));
	TCHAR exeFullPath[MAX_PATH];
	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	CString szfolder = exeFullPath;
	int pos = szfolder.ReverseFind('\\');
	szfolder = szfolder.Left(pos + 1);
	return szfolder;
}

void CRank::ListToExcel(CListCtrl* datalist, CString filepath, CString str[], int rowcount, int colcount)   //列表控件变量，存储文件路径，列表头的字符串数组，控件行数，控件列数
{
	CApplication app;
	CRange range;
	CRange usedrange;
	CWorkbook book;
	CWorkbooks books;
	CWorksheets sheets;
	CWorksheet sheet;
	//list控件数据写入Excel
	COleVariant
		covTrue((short)TRUE),
		covFalse((short)FALSE),
		covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	//创建Excel 服务器(启动Excel)
	if (!app.CreateDispatch(_T("Excel.Application"), NULL))
	{
		AfxMessageBox(_T("启动Excel服务器失败!"));
		return;
	}

	/*得到工作簿容器*/
	books.AttachDispatch(app.get_Workbooks());
	/*增加一个新的工作簿*/
	LPDISPATCH lpdisp = books.Add(covOptional);
	book.AttachDispatch(lpdisp);
	/*得到工作簿中的Sheet的容器*/
	sheets.AttachDispatch(book.get_Sheets());
	sheet = sheets.get_Item(COleVariant((short)1));   //得到第一个工作表
	CHeaderCtrl* pmyHeaderCtrl = datalist->GetHeaderCtrl(); //获取表头
	usedrange.AttachDispatch(sheet.get_UsedRange());
	try
	{
		//获取当前读取的EXCEL中活动的sheet
		usedrange.AttachDispatch(sheet.get_Cells());
		//清空Excel中的内容
		usedrange.ClearContents();
		//填入列名
		for (int i = 1; i <= colcount; i++)
		{
			range.AttachDispatch(usedrange.get_Item((_variant_t((long)1)),
				(_variant_t)(long)i).pdispVal);
			range.put_Value2((_variant_t(str[i - 1])));
		}
		//填充新内容
		CString	 str1;
		for (int row = 0; row < rowcount; row++)
		{
			for (int col = 0; col < colcount; col++)
			{
				str1 = datalist->GetItemText(row, col);
				range.AttachDispatch(usedrange.get_Item(_variant_t((long)row + 2),
					_variant_t((long)col + 1)).pdispVal);
				range.put_Value2(_variant_t(str1));
			}
		}
		book.SaveAs(COleVariant(filepath), covOptional, covOptional, covOptional,
			covOptional, covOptional, 1, covOptional, covOptional, covOptional,
			covOptional, covOptional, covOptional);
		usedrange.ReleaseDispatch();
		range.ReleaseDispatch();
		sheet.ReleaseDispatch();
		sheets.ReleaseDispatch();
		book.ReleaseDispatch();
		books.ReleaseDispatch();
		app.Quit();
		app.ReleaseDispatch();
		AfxMessageBox(L"保存成功");
		//m_used_range.AttachDispatch(m_used_range.get_Item(COleVariant((long)1), (COleVariant)(long)1).pdispVal);
	}
	catch (CException* e)
	{
		usedrange.ReleaseDispatch();
		range.ReleaseDispatch();
		sheet.ReleaseDispatch();
		sheets.ReleaseDispatch();
		book.ReleaseDispatch();
		books.ReleaseDispatch();
		app.Quit();
		app.ReleaseDispatch();
		AfxMessageBox(L"保存失败");
	}
}

void CRank::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString strlisthead[3];           //输入列表头
	strlisthead[0] = L"排名";
	strlisthead[1] = L"玩家";
	strlisthead[2] = L"分数";
	CString strBookPath = GetModuleDir() + _T("res\\Rankings.xlsx");      //存储文件路径
	int colcount = m_programLangList.GetHeaderCtrl()->GetItemCount();   //求控件列数
	int rowcount = m_programLangList.GetItemCount();           //求控件行数
	//函数调用
	ListToExcel(&m_programLangList, strBookPath, strlisthead, rowcount, colcount);
	CTikSEUDlg* pMain = (CTikSEUDlg*)AfxGetMainWnd();
	pMain->m_pTipDlg2 = NULL;
	CDialogEx::OnClose();
	delete this;
}
