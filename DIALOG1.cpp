// DIALOG1.cpp: 实现文件
//

#include "pch.h"
#include "TikSEU.h"
#include "afxdialogex.h"
#include "DIALOG1.h"
#include "CNAME.h"

// DIALOG1 对话框

IMPLEMENT_DYNAMIC(DIALOG1, CDialogEx)

DIALOG1::DIALOG1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_HscrollEdit(0)
{

}

DIALOG1::~DIALOG1()
{
}

void DIALOG1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HORI_SCROLLBAR, m_horiScrollbar);
	DDX_Text(pDX, IDC_HSCROLL_EDIT, m_HscrollEdit);
}


BEGIN_MESSAGE_MAP(DIALOG1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DIALOG1::OnBnClickedButton1)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_HSCROLL_EDIT, &DIALOG1::OnEnChangeHscrollEdit)
END_MESSAGE_MAP()


// DIALOG1 消息处理程序


void DIALOG1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nname;
	CNAME name;
	nname = name.DoModal();
	if (IDCANCEL == nname)return;
	UpdateData(TRUE);
	UpdateData(FALSE);
}


BOOL DIALOG1::OnInitDialog()
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

		m_horiScrollbar.SetScrollRange(0, 100);
		m_horiScrollbar.SetScrollPos(20);
		// TODO: 在此添加额外的初始化代码

		return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
	}



void DIALOG1::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int pos = m_horiScrollbar.GetScrollPos(); // 获取水平滚动条当前位置
	
	switch (nSBCode)
	{
		// 如果向左滚动一列，则 pos 减 1
	case SB_LINEUP:
		pos -= 1;
		break;
		// 如果向右滚动一列，则 pos 加 1
	case SB_LINEDOWN:
		pos += 1;
		break;
		// 如果向左滚动一页，则 pos 减 10
	case SB_PAGEUP:
		pos -= 10;
		break;
		// 如果向右滚动一页，则 pos 加 10
	case SB_PAGEDOWN:
		pos += 10;
		break;
		// 如果滚动到最左端，则 pos 为 1
	case SB_TOP:
		pos = 1;
		break;
		// 如果滚动到最右端，则 pos 为 100
	case SB_BOTTOM:
		pos = 100;
		break;
		// 如果拖动滚动块滚动到指定位置，则 pos 赋值为 nPos 的值
	case SB_THUMBPOSITION:
		pos = nPos;
		break;
		// 下面的 m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到 default 分支，所以在此处设置编辑框中显示数值
	default:
		SetDlgItemInt(IDC_HSCROLL_EDIT, pos);
		return;
	}
	// 设置滚动块位置
	m_horiScrollbar.SetScrollPos(pos);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}



void DIALOG1::OnEnChangeHscrollEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	UpdateData(TRUE);
	if (m_HscrollEdit > 100|| m_HscrollEdit<0)m_HscrollEdit = 0;//如果输入的音量值不合要求则重新归0；
	m_horiScrollbar.SetScrollPos(m_HscrollEdit);//设置滚动条；
	UpdateData(FALSE);
	// TODO:  在此添加控件通知处理程序代码
}
