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
	void ShowText();	//Ϊ��֮ƥ��İ�ť��ʾ�ı�
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
	ELM* CreateELM();	//������Ԫ��
	void GMStart();		//��Ϸ��ʼ
	/*	��Ϸ��ʼ
	* ����
	* �������81��Ԫ��
	* ��˳��ƥ�����ť
	* Ϊ��ťװ����ʾ����
	*/
	void Load();		//��ʾ����
	void Exchange(int x1,int y1,int x2,int y2);	//�ɹ���������Ԫ��
	/*	����Ԫ��
	* ����
	* �ж��Ƿ�����Ч
	* �ж��Ƿ�����µ���Ч
	* �����ض�����������
	*/
	void ClearELM(int x, int y);	//����Ԫ��

};