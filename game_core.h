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
	int ELMText;
	int X;
	int Y;
	int ELMType;
	int ELMStatus;
public:
	ELM() {
		Bid = 0;
		ELMText = 1;
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
	CString GetText();	//为与之匹配的按钮提供文本
	int GetBid();
};
