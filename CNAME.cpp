// CNAME.cpp: 实现文件
//

#include "pch.h"
#include "TikSEU.h"
#include "afxdialogex.h"
#include "CNAME.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

// CNAME 对话框

IMPLEMENT_DYNAMIC(CNAME, CDialogEx)

CNAME::CNAME(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NAME, pParent)
{

}

CNAME::~CNAME()
{
	PlaySound(_T("E:\\Users\\tik\\res\\GameStart.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void CNAME::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNAME, CDialogEx)
END_MESSAGE_MAP()


// CNAME 消息处理程序


BOOL CNAME::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	PlaySound(_T("E:\\Users\\tik\\res\\Ending.wav"), NULL, SND_FILENAME | SND_ASYNC);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
