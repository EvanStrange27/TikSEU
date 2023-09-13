#pragma once
#include "afxdialogex.h"


// CRank 对话框

class CRank : public CDialogEx
{
	DECLARE_DYNAMIC(CRank)

public:
	CRank(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CRank();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Rank };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
