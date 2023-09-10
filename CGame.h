#pragma once
#include "afxdialogex.h"


// CGame 对话框

class CGame : public CDialogEx
{
	DECLARE_DYNAMIC(CGame)

public:
	CGame(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame();
	CFont* m_Font;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Game };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//CButton B1;
	template <int bid> afx_msg void OnBnClickedButton();
	CButton BTN[100];
};
