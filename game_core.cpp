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
	case 1:Text = "��"; break;
	case 2:Text = "��"; break;
	case 3:Text = "��"; break;
	case 4:Text = "��"; break;
	case 5:Text = "��"; break;
	}
	return Text;
}

int ELM::GetBid() {
	return Bid;
}
