#include "pch.h"
#include "TikSEU.h"
#include "TikSEUDlg.h"
#include "afxdialogex.h"
#include "CGame.h"
#include "DIALOG1.h"
#include "string"
using std::string;

class ELM
{
private:
	int Bid;
	int ElmText;
	int X;
	int Y;
	int ELMType;
	int ELMStatus;
public:
	ELM() {
		Bid = 0;
		ElmText = 1;
		X = 0;
		Y = 0;
		ELMType = 1;
		ELMStatus = 1;
	}
	~ELM() {};
	void SetBid(int bid);
	void SetXY(int x,int y);
	void SetType(int type);
	void SetText(int text);
	void SetStatus(int sta);
	void ShowText();	//为与之匹配的按钮显示文本
};

class GM
{
private:
	ELM* elm;
	ELM* Pos[10][10];
	int Score;
public:
	GM() {
		elm = NULL;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j <= 10; j++) {
				Pos[i][j] = NULL;
			}
		}
		Score = 0;
	}
	~GM() {
	
	};
	//以一个特效类型创建新元素
	ELM* CreateELM(int x,int y,int text,int type=1);
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
	void Exchange(int x1,int y1,int x2,int y2);	
	//消除元素
	void ClearELM(int x, int y);
	/*	下落填充
	* 递归循环
	* 从最下方一个开始，指针指向上一行，直到最下面一行不为NULL
	*/
	void Fall(int y);
	// 判断是否可以消除
	void Judge(bool ifstart=0);
};