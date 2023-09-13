#pragma once
#include "afxdialogex.h"
#include "CGame.h"


// CSaveDlg 对话框

class CSaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSaveDlg)

public:
	CSaveDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSaveDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Save };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic SaveScore;
	int Score;
	CString ScoreStr;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CString SaveName;
	CGame* parent;
};
