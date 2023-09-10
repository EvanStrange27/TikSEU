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
{

}

DIALOG1::~DIALOG1()
{
}

void DIALOG1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DIALOG1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DIALOG1::OnBnClickedButton1)
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
