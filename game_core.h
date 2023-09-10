#include "pch.h"
#include "TikSEU.h"
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
public:
	ELM() {
		Bid = 0;
		Text = "0";
		X = 0;
		Y = 0;
	}
	~ELM() {};
	void SetBid(int bid);
	void SetXY(int x,int y);
};

class GM
{
private:
	ELM* elm;

public:
	GM() {
		elm = NULL;
	}
	~GM() {};
	ELM* CreateELM();

};