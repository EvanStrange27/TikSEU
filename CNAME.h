#pragma once
#include "afxdialogex.h"


// CNAME 对话框

class CNAME : public CDialogEx
{
	DECLARE_DYNAMIC(CNAME)

public:
	CNAME(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CNAME();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
