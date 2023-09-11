#pragma once
#include "afxdialogex.h"


class ELM
{
private:
	int ELMText;
	int ELMType;
	int ELMStatus;
	static int count;
	int Eid;
public:
	ELM() {
		ELMText = 0;
		ELMType = 1;
		ELMStatus = 0;
		Eid = 0;
	}
	~ELM() {};
	void SetType(int type);
	void SetText(int text);
	void SetStatus(int sta);
	void UpdateEid();
	CString GetText();	//为与之匹配的按钮提供文本
};

// CGame 对话框

class CGame : public CDialogEx
{
	DECLARE_DYNAMIC(CGame)

public:
	CGame(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame();

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
	int AlCh;
	//static CWnd* Game_cwnd;

	//以下为Game Core
	ELM* elm;
	ELM* Pos[10][10];
	int Score;
	ELM* CreateELM(int text = 0, int type = 1);
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
	void Fall();
	// 判断是否可以消除
	void Judge(bool ifstart = 0);
	//获取横坐标
	int BidtoX(int bid);
	//获取纵坐标
	int BidtoY(int bid);
	//获取Bid
	int XYtoBid(int x, int y);
	//判断二者是否相邻
	bool JudgeEx(int bid1, int bid2);
};
