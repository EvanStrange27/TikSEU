#include "pch.h"
#include "game_core.h"
#include "ctime"
#include "random"
using std::string;

void ELM::SetBid(int bid) {
	Bid = bid;
}

void ELM::SetXY(int x,int y) {
	X = x;
	Y = y;
}

void ELM::SetType(int type) {
	ELMType = type;
}

void ELM::SetText(int text) {
	ELMText = text;
}

void ELM::SetStatus(int sta) {
	ELMStatus = sta;
}

CString ELM::GetText() {
	CString Text;
	switch (ELMText) {
	case 1:Text = "东"; break;
	case 2:Text = "南"; break;
	case 3:Text = "西"; break;
	case 4:Text = "北"; break;
	case 5:Text = "中"; break;
	}
	return Text;
}

int ELM::GetBid() {
	return Bid;
}
