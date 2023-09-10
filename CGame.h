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
	virtual BOOL OnInitDialog();
	static CWnd* Game_cwnd;

	//以下为Game Core
	ELM* elm;
	ELM* Pos[10][10];
	int Score;
	ELM* CreateELM(int x, int y, int bid, int text, int type = 1);
	/*	游戏开始
	* 流程
	* 随机创建81个元素
	* 按顺序匹配给按钮
	* 自行判断是否可消除，并杜绝这种情况
	* 为按钮装载显示名字
	*/
	void GMStart();
	//显示名字
	void Load();
	/*	交换元素
	* 流程
	* 判断是否可以消除
	* 判断是否含有特效
	* 判断是否产生新的特效
	* 调用特定的消除函数
	*/
	//成功交换两个元素
	void Exchange(int x1, int y1, int x2, int y2);
	//消除元素
	void ClearELM(int x, int y);
	/*	下落填充
	* 递归循环
	* 从最下方一个开始，指针指向上一行，直到最下面一行不为NULL
	*/
	void Fall(int y);
	// 判断是否可以消除
	void Judge(bool ifstart = 0);
};
