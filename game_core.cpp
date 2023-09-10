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
	ELMType = text;
}

void ELM::SetStatus(int sta) {
	ELMStatus = sta;
}

void ELM::ShowText() {

}

ELM* GM::CreateELM(int x,int y,int text, int type) {
	elm = new ELM();
	elm->SetType(type);
	elm->SetText(text);
	elm->SetXY(x,y);
	return elm;
}

void GM::GMStart() {
	std::default_random_engine dre;				 // 产生随机非负数
	std::uniform_int_distribution<int> uid(1,5); // 左闭右闭区间，产生均匀分布的整数
	dre.seed(time(0));

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			Pos[i][j] = CreateELM(i, j, uid(dre));
		}
	}

	Judge(1);
	Load();
}

void GM::Load() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			
		}
	}
}

void GM::Exchange(int x1, int y1, int x2, int y2) {

}

void GM::ClearELM(int x, int y) {

}

void GM::Fall(int y) {

}

void GM::Judge(bool ifstart) {

}