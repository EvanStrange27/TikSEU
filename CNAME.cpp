// CNAME.cpp: 实现文件
//

#include "pch.h"
#include "TikSEU.h"
#include "afxdialogex.h"
#include "CNAME.h"


// CNAME 对话框

IMPLEMENT_DYNAMIC(CNAME, CDialogEx)

CNAME::CNAME(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NAME, pParent)
{

}

CNAME::~CNAME()
{
}

void CNAME::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNAME, CDialogEx)
END_MESSAGE_MAP()


// CNAME 消息处理程序
