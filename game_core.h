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
	~GM() {
	
	};
	//��һ����Ч���ʹ�����Ԫ��
	ELM* CreateELM(int x,int y,int text,int type=1);
	/*	��Ϸ��ʼ
	* ����
	* �������81��Ԫ��
	* ��˳��ƥ�����ť
	* �����ж��Ƿ�����������ž��������
	* Ϊ��ťװ����ʾ����
	*/
	void GMStart();	
	//��ʾ����
	void Load();
	/*	����Ԫ��
	* ����
	* �ж��Ƿ��������
	* �ж��Ƿ�����Ч
	* �ж��Ƿ�����µ���Ч
	* �����ض�����������
	*/
	//�ɹ���������Ԫ��
	void Exchange(int x1,int y1,int x2,int y2);	
	//����Ԫ��
	void ClearELM(int x, int y);
	/*	�������
	* �ݹ�ѭ��
	* �����·�һ����ʼ��ָ��ָ����һ�У�ֱ��������һ�в�ΪNULL
	*/
	void Fall(int y);
	// �ж��Ƿ��������
	void Judge(bool ifstart=0);
};