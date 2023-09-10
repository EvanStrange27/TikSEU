// DIALOG1.cpp: 实现文件
//

#include "pch.h"
#include "TikSEU.h"
#include "afxdialogex.h"
#include "DIALOG1.h"


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
END_MESSAGE_MAP()


// DIALOG1 消息处理程序
