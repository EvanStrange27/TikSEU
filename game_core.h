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
	string Text;
	int X;
	int Y;
	int ELMType;
public:
	ELM() {
		Bid = 0;
		Text = "0";
		X = 0;
		Y = 0;
		ELMType = 1;
	}
	~ELM() {};
	void SetBid(int bid);
	void SetXY(int x,int y);
	void SetType(int type);
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
	~GM() {};
	ELM* CreateELM();	//创建新元素
	void GMStart();		//游戏开始
	/*	游戏开始
	* 流程
	* 随机创建81个元素
	* 按顺序匹配给按钮
	* 为按钮装载显示名字
	*/
	void Load();		//显示名字
	void Exchange(int x1,int y1,int x2,int y2);	//成功交换两个元素
	/*	交换元素
	* 流程
	* 判断是否含有特效
	* 判断是否产生新的特效
	* 调用特定的消除函数
	*/
	void ClearELM(int x, int y);	//消除元素

};