
// TikSEUDlg.h: 头文件
//

#pragma once
#include "DIALOG1.h"
#include "CGame.h"
#include "CRank.h"

// CTikSEUDlg 对话框
class CTikSEUDlg : public CDialogEx
{
// 构造
public:
	CTikSEUDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIKSEU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CButton Main_Btm_Setting;
	DIALOG1 Win_Setting;
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedPlay();
	DIALOG1* m_pTipDlg = NULL;
	CGame* m_pTipDlg1 = NULL;
	CRank* m_pTipDlg2 = NULL;
	afx_msg void OnBnClickedRanking();
	CStatic Pic;
	void ShowImg(CString path, INT control_id);
};
