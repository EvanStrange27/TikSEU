// CRank.cpp: 实现文件
//

#include "pch.h"
#include "TikSEU.h"
#include "afxdialogex.h"
#include "CRank.h"


// CRank 对话框

IMPLEMENT_DYNAMIC(CRank, CDialogEx)

CRank::CRank(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Rank, pParent)
{

}

CRank::~CRank()
{
}

void CRank::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRank, CDialogEx)
END_MESSAGE_MAP()


// CRank 消息处理程序
