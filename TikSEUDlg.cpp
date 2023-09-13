
// TikSEUDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "TikSEU.h"
#include "TikSEUDlg.h"
#include "afxdialogex.h"
#include <mmsystem.h>
#include "atlimage.h"
#pragma comment(lib,"winmm.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTikSEUDlg 对话框



CTikSEUDlg::CTikSEUDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TIKSEU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTikSEUDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, Main_Btm_Setting);
	DDX_Control(pDX, IDC_PIC, Pic);
}

BEGIN_MESSAGE_MAP(CTikSEUDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTikSEUDlg::OnBnClickedButton1)
	ON_BN_CLICKED(Main_Quit, &CTikSEUDlg::OnBnClickedQuit)
	ON_BN_CLICKED(Main_Play, &CTikSEUDlg::OnBnClickedPlay)
	ON_BN_CLICKED(Main_Ranking, &CTikSEUDlg::OnBnClickedRanking)
END_MESSAGE_MAP()


// CTikSEUDlg 消息处理程序

BOOL CTikSEUDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	PlaySound(_T("./res/GameStart.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	//ShowImg(L"./res/backround.bmp", IDC_PIC);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTikSEUDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTikSEUDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTikSEUDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTikSEUDlg::OnBnClickedButton1()
{
	
	if (NULL == m_pTipDlg)
	{
		// 创建非模态对话框实例   
		m_pTipDlg = new DIALOG1();
		m_pTipDlg->Create(IDD_DIALOG1, this);
	}
	// 显示非模态对话框   
	m_pTipDlg->ShowWindow(SW_SHOW);

}


void CTikSEUDlg::OnBnClickedQuit()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CTikSEUDlg::OnBnClickedPlay()
{
	// TODO: 在此添加控件通知处理程序代码
	if (NULL == m_pTipDlg1)
	{
		// 创建非模态对话框实例   
		m_pTipDlg1 = new CGame();
		m_pTipDlg1->Create(Game, this);
	}
	// 显示非模态对话框   
	m_pTipDlg1->ShowWindow(SW_SHOW);
	
}



void CTikSEUDlg::OnBnClickedRanking()
{
	// TODO: 在此添加控件通知处理程序代码
	if (NULL == m_pTipDlg2)
	{
		// 创建非模态对话框实例   
		m_pTipDlg2 = new CRank();
		m_pTipDlg2->Create(Rank, this);
	}
	// 显示非模态对话框   
	m_pTipDlg2->ShowWindow(SW_SHOW);
}

/******************************************
参数说明：
		  CString path //图片路径
		  INT control_id //picture控件的id
Tip：使用该函数要修改picture控件id 并且添加变量
******************************************/
void CTikSEUDlg::ShowImg(CString path, INT control_id)
{
	CImage img;
	//同一个控件多次加载图片会使程序崩溃，因此需要销毁掉原来的内容
	if (img!=NULL)
	{
		img.Destroy();
	}

	img.Load(path);//加载图片路径
	CRect rect;
	GetDlgItem(control_id)->GetWindowRect(&rect);//将窗口矩形显示到picture上

	CWnd* pCwnd = GetDlgItem(control_id);//获取picture控件窗口的句柄
	CDC* pDc = pCwnd->GetDC();//获取picture控件句柄 
	img.Draw(pDc->m_hDC, 0, 0, rect.right - rect.left, rect.bottom - rect.top);//将图片画到picture控件所表示的范围，并且适应控件大小
	ReleaseDC(pDc);//释放pDc
}
