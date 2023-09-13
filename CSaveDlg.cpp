// CSaveDlg.cpp: 实现文件
//

#include "pch.h"
#include "TikSEU.h"
#include "afxdialogex.h"
#include "CSaveDlg.h"


// CSaveDlg 对话框

IMPLEMENT_DYNAMIC(CSaveDlg, CDialogEx)

CSaveDlg::CSaveDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Save, pParent)
	, SaveName(_T(""))
{
	Score = 0;
	parent = NULL;
}

CSaveDlg::~CSaveDlg()
{
}

void CSaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SaveScore, SaveScore);
	DDX_Text(pDX, IDC_SaveName, SaveName);
}


BEGIN_MESSAGE_MAP(CSaveDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSaveDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSaveDlg 消息处理程序


BOOL CSaveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	ScoreStr.Format(L"%d", Score);
	SaveScore.SetWindowText(ScoreStr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSaveDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	parent->GamerID = SaveName;
	CDialogEx::OnOK();
}
