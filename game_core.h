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
	string text;
	int x;
	int y;
public:
	ELM() {
		Bid = 0;
		text = "0";
		x = 0;
		y = 0;
	}
	~ELM() {};
	void SetBid();
	void SetXY(int intx,int inty);
};