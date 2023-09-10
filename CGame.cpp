// CGame.cpp: 实现文件
//

#include "pch.h"
#include "TikSEU.h"
#include "afxdialogex.h"
#include "CGame.h"
#include "game_core.h"

// CGame 对话框

IMPLEMENT_DYNAMIC(CGame, CDialogEx)

CGame::CGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Game, pParent)
{

}

CGame::~CGame()
{
}

void CGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, B1);
}


BEGIN_MESSAGE_MAP(CGame, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGame::OnBnClickedButton1)
END_MESSAGE_MAP()


// CGame 消息处理程序


void CGame::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
