#pragma once
#include "afxdialogex.h"
#include "mmsystem.h"

// DIALOG1 对话框

class DIALOG1 : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG1)

public:
	DIALOG1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DIALOG1();
	MIXERCONTROLDETAILS_SIGNED volStruct;

	MIXERCONTROLDETAILS mxcd;

	MIXERLINECONTROLS mxlc;

	MIXERLINE mxl;

	MIXERCONTROL mxc;

	HMIXER m_hmx;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CScrollBar m_horiScrollbar;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int m_HscrollEdit;
	afx_msg void OnEnChangeHscrollEdit();
};
