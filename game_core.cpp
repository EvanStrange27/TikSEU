#include "pch.h"
#include "game_core.h"
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

void ELM::ShowText() {

}

ELM* GM::CreateELM() {
	return NULL;
}

void GM::GMStart() {

}

void GM::Load() {
	
}

void GM::Exchange(int x1, int y1, int x2, int y2) {

}

void GM::ClearELM(int x, int y) {

}