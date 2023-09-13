#pragma once
#include "afxdialogex.h"


// CRank 对话框

class CRank : public CDialogEx
{
	DECLARE_DYNAMIC(CRank)

public:
	CRank(CWnd* pParent = nullptr);   // 标准构造函数
	CRank(CString id,int score,CWnd* pParent = nullptr);
	virtual ~CRank();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Rank };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	int m_rows;
	int RowToId[20];
	void ReadAllItem(CString sExcelFile);
	CString GetModuleDir();
	void ListToExcel(CListCtrl* datalist, CString filepath, CString str[], int rowcount, int colcount);
	virtual BOOL OnInitDialog();
	CListCtrl m_programLangList;
	CString NewID;
	int NewScore;
	afx_msg void OnClose();
	bool FromParent;
};
