// CGame.cpp: 实现文件
//

#include "pch.h"
#include "TikSEU.h"
#include "afxdialogex.h"
#include "CGame.h"
#include "ctime"
#include "random"
#include "string"
#include "cmath"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using std::string;
int ELM::count = 0;
bool ifstart;
std::default_random_engine dre;					// 产生随机非负数
std::uniform_int_distribution<int> uid(1, 5);	// 左闭右闭区间，产生均匀分布的整数
// CGame 对话框

IMPLEMENT_DYNAMIC(CGame, CDialogEx)

CGame::CGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Game, pParent)
{
	elm = NULL;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= 10; j++) {
			Pos[i][j] = NULL;
		}
	}
	Score = 0;
	AlCh = 0;
}

CGame::~CGame()
{
	PlaySound(_T("./res/GameStart.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void CGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BUTTON1, B1);
	//逐个绑定按钮
	/*
	for (int i = 1; i <= 81; i++) {
		DDX_Control(pDX, 999+i, BTN[i]);
	}
	*/
	DDX_Control(pDX, IDC_BUTTON1, BTN[1]);
	DDX_Control(pDX, IDC_BUTTON2, BTN[2]);
	DDX_Control(pDX, IDC_BUTTON3, BTN[3]);
	DDX_Control(pDX, IDC_BUTTON4, BTN[4]);
	DDX_Control(pDX, IDC_BUTTON5, BTN[5]);
	DDX_Control(pDX, IDC_BUTTON6, BTN[6]);
	DDX_Control(pDX, IDC_BUTTON7, BTN[7]);
	DDX_Control(pDX, IDC_BUTTON8, BTN[8]);
	DDX_Control(pDX, IDC_BUTTON9, BTN[9]);
	DDX_Control(pDX, IDC_BUTTON10, BTN[10]);
	DDX_Control(pDX, IDC_BUTTON11, BTN[11]);
	DDX_Control(pDX, IDC_BUTTON12, BTN[12]);
	DDX_Control(pDX, IDC_BUTTON13, BTN[13]);
	DDX_Control(pDX, IDC_BUTTON14, BTN[14]);
	DDX_Control(pDX, IDC_BUTTON15, BTN[15]);
	DDX_Control(pDX, IDC_BUTTON16, BTN[16]);
	DDX_Control(pDX, IDC_BUTTON17, BTN[17]);
	DDX_Control(pDX, IDC_BUTTON18, BTN[18]);
	DDX_Control(pDX, IDC_BUTTON19, BTN[19]);
	DDX_Control(pDX, IDC_BUTTON20, BTN[20]);
	DDX_Control(pDX, IDC_BUTTON21, BTN[21]);
	DDX_Control(pDX, IDC_BUTTON22, BTN[22]);
	DDX_Control(pDX, IDC_BUTTON23, BTN[23]);
	DDX_Control(pDX, IDC_BUTTON24, BTN[24]);
	DDX_Control(pDX, IDC_BUTTON25, BTN[25]);
	DDX_Control(pDX, IDC_BUTTON26, BTN[26]);
	DDX_Control(pDX, IDC_BUTTON27, BTN[27]);
	DDX_Control(pDX, IDC_BUTTON28, BTN[28]);
	DDX_Control(pDX, IDC_BUTTON29, BTN[29]);
	DDX_Control(pDX, IDC_BUTTON30, BTN[30]);
	DDX_Control(pDX, IDC_BUTTON31, BTN[31]);
	DDX_Control(pDX, IDC_BUTTON32, BTN[32]);
	DDX_Control(pDX, IDC_BUTTON33, BTN[33]);
	DDX_Control(pDX, IDC_BUTTON34, BTN[34]);
	DDX_Control(pDX, IDC_BUTTON35, BTN[35]);
	DDX_Control(pDX, IDC_BUTTON36, BTN[36]);
	DDX_Control(pDX, IDC_BUTTON37, BTN[37]);
	DDX_Control(pDX, IDC_BUTTON38, BTN[38]);
	DDX_Control(pDX, IDC_BUTTON39, BTN[39]);
	DDX_Control(pDX, IDC_BUTTON40, BTN[40]);
	DDX_Control(pDX, IDC_BUTTON41, BTN[41]);
	DDX_Control(pDX, IDC_BUTTON42, BTN[42]);
	DDX_Control(pDX, IDC_BUTTON43, BTN[43]);
	DDX_Control(pDX, IDC_BUTTON44, BTN[44]);
	DDX_Control(pDX, IDC_BUTTON45, BTN[45]);
	DDX_Control(pDX, IDC_BUTTON46, BTN[46]);
	DDX_Control(pDX, IDC_BUTTON47, BTN[47]);
	DDX_Control(pDX, IDC_BUTTON48, BTN[48]);
	DDX_Control(pDX, IDC_BUTTON49, BTN[49]);
	DDX_Control(pDX, IDC_BUTTON50, BTN[50]);
	DDX_Control(pDX, IDC_BUTTON51, BTN[51]);
	DDX_Control(pDX, IDC_BUTTON52, BTN[52]);
	DDX_Control(pDX, IDC_BUTTON53, BTN[53]);
	DDX_Control(pDX, IDC_BUTTON54, BTN[54]);
	DDX_Control(pDX, IDC_BUTTON55, BTN[55]);
	DDX_Control(pDX, IDC_BUTTON56, BTN[56]);
	DDX_Control(pDX, IDC_BUTTON57, BTN[57]);
	DDX_Control(pDX, IDC_BUTTON58, BTN[58]);
	DDX_Control(pDX, IDC_BUTTON59, BTN[59]);
	DDX_Control(pDX, IDC_BUTTON60, BTN[60]);
	DDX_Control(pDX, IDC_BUTTON61, BTN[61]);
	DDX_Control(pDX, IDC_BUTTON62, BTN[62]);
	DDX_Control(pDX, IDC_BUTTON63, BTN[63]);
	DDX_Control(pDX, IDC_BUTTON64, BTN[64]);
	DDX_Control(pDX, IDC_BUTTON65, BTN[65]);
	DDX_Control(pDX, IDC_BUTTON66, BTN[66]);
	DDX_Control(pDX, IDC_BUTTON67, BTN[67]);
	DDX_Control(pDX, IDC_BUTTON68, BTN[68]);
	DDX_Control(pDX, IDC_BUTTON69, BTN[69]);
	DDX_Control(pDX, IDC_BUTTON70, BTN[70]);
	DDX_Control(pDX, IDC_BUTTON71, BTN[71]);
	DDX_Control(pDX, IDC_BUTTON72, BTN[72]);
	DDX_Control(pDX, IDC_BUTTON73, BTN[73]);
	DDX_Control(pDX, IDC_BUTTON74, BTN[74]);
	DDX_Control(pDX, IDC_BUTTON75, BTN[75]);
	DDX_Control(pDX, IDC_BUTTON76, BTN[76]);
	DDX_Control(pDX, IDC_BUTTON77, BTN[77]);
	DDX_Control(pDX, IDC_BUTTON78, BTN[78]);
	DDX_Control(pDX, IDC_BUTTON79, BTN[79]);
	DDX_Control(pDX, IDC_BUTTON80, BTN[80]);
	DDX_Control(pDX, IDC_BUTTON81, BTN[81]);
}


BEGIN_MESSAGE_MAP(CGame, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGame::OnBnClickedButton<1>)
	ON_BN_CLICKED(IDC_BUTTON2, &CGame::OnBnClickedButton<2>)
	ON_BN_CLICKED(IDC_BUTTON3, &CGame::OnBnClickedButton<3>)
	ON_BN_CLICKED(IDC_BUTTON4, &CGame::OnBnClickedButton<4>)
	ON_BN_CLICKED(IDC_BUTTON5, &CGame::OnBnClickedButton<5>)
	ON_BN_CLICKED(IDC_BUTTON6, &CGame::OnBnClickedButton<6>)
	ON_BN_CLICKED(IDC_BUTTON7, &CGame::OnBnClickedButton<7>)
	ON_BN_CLICKED(IDC_BUTTON8, &CGame::OnBnClickedButton<8>)
	ON_BN_CLICKED(IDC_BUTTON9, &CGame::OnBnClickedButton<9>)
	ON_BN_CLICKED(IDC_BUTTON10, &CGame::OnBnClickedButton<10>)
	ON_BN_CLICKED(IDC_BUTTON11, &CGame::OnBnClickedButton<11>)
	ON_BN_CLICKED(IDC_BUTTON12, &CGame::OnBnClickedButton<12>)
	ON_BN_CLICKED(IDC_BUTTON13, &CGame::OnBnClickedButton<13>)
	ON_BN_CLICKED(IDC_BUTTON14, &CGame::OnBnClickedButton<14>)
	ON_BN_CLICKED(IDC_BUTTON15, &CGame::OnBnClickedButton<15>)
	ON_BN_CLICKED(IDC_BUTTON16, &CGame::OnBnClickedButton<16>)
	ON_BN_CLICKED(IDC_BUTTON17, &CGame::OnBnClickedButton<17>)
	ON_BN_CLICKED(IDC_BUTTON18, &CGame::OnBnClickedButton<18>)
	ON_BN_CLICKED(IDC_BUTTON19, &CGame::OnBnClickedButton<19>)
	ON_BN_CLICKED(IDC_BUTTON20, &CGame::OnBnClickedButton<20>)
	ON_BN_CLICKED(IDC_BUTTON21, &CGame::OnBnClickedButton<21>)
	ON_BN_CLICKED(IDC_BUTTON22, &CGame::OnBnClickedButton<22>)
	ON_BN_CLICKED(IDC_BUTTON23, &CGame::OnBnClickedButton<23>)
	ON_BN_CLICKED(IDC_BUTTON24, &CGame::OnBnClickedButton<24>)
	ON_BN_CLICKED(IDC_BUTTON25, &CGame::OnBnClickedButton<25>)
	ON_BN_CLICKED(IDC_BUTTON26, &CGame::OnBnClickedButton<26>)
	ON_BN_CLICKED(IDC_BUTTON27, &CGame::OnBnClickedButton<27>)
	ON_BN_CLICKED(IDC_BUTTON28, &CGame::OnBnClickedButton<28>)
	ON_BN_CLICKED(IDC_BUTTON29, &CGame::OnBnClickedButton<29>)
	ON_BN_CLICKED(IDC_BUTTON30, &CGame::OnBnClickedButton<30>)
	ON_BN_CLICKED(IDC_BUTTON31, &CGame::OnBnClickedButton<31>)
	ON_BN_CLICKED(IDC_BUTTON32, &CGame::OnBnClickedButton<32>)
	ON_BN_CLICKED(IDC_BUTTON33, &CGame::OnBnClickedButton<33>)
	ON_BN_CLICKED(IDC_BUTTON34, &CGame::OnBnClickedButton<34>)
	ON_BN_CLICKED(IDC_BUTTON35, &CGame::OnBnClickedButton<35>)
	ON_BN_CLICKED(IDC_BUTTON36, &CGame::OnBnClickedButton<36>)
	ON_BN_CLICKED(IDC_BUTTON37, &CGame::OnBnClickedButton<37>)
	ON_BN_CLICKED(IDC_BUTTON38, &CGame::OnBnClickedButton<38>)
	ON_BN_CLICKED(IDC_BUTTON39, &CGame::OnBnClickedButton<39>)
	ON_BN_CLICKED(IDC_BUTTON40, &CGame::OnBnClickedButton<40>)
	ON_BN_CLICKED(IDC_BUTTON41, &CGame::OnBnClickedButton<41>)
	ON_BN_CLICKED(IDC_BUTTON42, &CGame::OnBnClickedButton<42>)
	ON_BN_CLICKED(IDC_BUTTON43, &CGame::OnBnClickedButton<43>)
	ON_BN_CLICKED(IDC_BUTTON44, &CGame::OnBnClickedButton<44>)
	ON_BN_CLICKED(IDC_BUTTON45, &CGame::OnBnClickedButton<45>)
	ON_BN_CLICKED(IDC_BUTTON46, &CGame::OnBnClickedButton<46>)
	ON_BN_CLICKED(IDC_BUTTON47, &CGame::OnBnClickedButton<47>)
	ON_BN_CLICKED(IDC_BUTTON48, &CGame::OnBnClickedButton<48>)
	ON_BN_CLICKED(IDC_BUTTON49, &CGame::OnBnClickedButton<49>)
	ON_BN_CLICKED(IDC_BUTTON50, &CGame::OnBnClickedButton<50>)
	ON_BN_CLICKED(IDC_BUTTON51, &CGame::OnBnClickedButton<51>)
	ON_BN_CLICKED(IDC_BUTTON52, &CGame::OnBnClickedButton<52>)
	ON_BN_CLICKED(IDC_BUTTON53, &CGame::OnBnClickedButton<53>)
	ON_BN_CLICKED(IDC_BUTTON54, &CGame::OnBnClickedButton<54>)
	ON_BN_CLICKED(IDC_BUTTON55, &CGame::OnBnClickedButton<55>)
	ON_BN_CLICKED(IDC_BUTTON56, &CGame::OnBnClickedButton<56>)
	ON_BN_CLICKED(IDC_BUTTON57, &CGame::OnBnClickedButton<57>)
	ON_BN_CLICKED(IDC_BUTTON58, &CGame::OnBnClickedButton<58>)
	ON_BN_CLICKED(IDC_BUTTON59, &CGame::OnBnClickedButton<59>)
	ON_BN_CLICKED(IDC_BUTTON60, &CGame::OnBnClickedButton<60>)
	ON_BN_CLICKED(IDC_BUTTON61, &CGame::OnBnClickedButton<61>)
	ON_BN_CLICKED(IDC_BUTTON62, &CGame::OnBnClickedButton<62>)
	ON_BN_CLICKED(IDC_BUTTON63, &CGame::OnBnClickedButton<63>)
	ON_BN_CLICKED(IDC_BUTTON64, &CGame::OnBnClickedButton<64>)
	ON_BN_CLICKED(IDC_BUTTON65, &CGame::OnBnClickedButton<65>)
	ON_BN_CLICKED(IDC_BUTTON66, &CGame::OnBnClickedButton<66>)
	ON_BN_CLICKED(IDC_BUTTON67, &CGame::OnBnClickedButton<67>)
	ON_BN_CLICKED(IDC_BUTTON68, &CGame::OnBnClickedButton<68>)
	ON_BN_CLICKED(IDC_BUTTON69, &CGame::OnBnClickedButton<69>)
	ON_BN_CLICKED(IDC_BUTTON70, &CGame::OnBnClickedButton<70>)
	ON_BN_CLICKED(IDC_BUTTON71, &CGame::OnBnClickedButton<71>)
	ON_BN_CLICKED(IDC_BUTTON72, &CGame::OnBnClickedButton<72>)
	ON_BN_CLICKED(IDC_BUTTON73, &CGame::OnBnClickedButton<73>)
	ON_BN_CLICKED(IDC_BUTTON74, &CGame::OnBnClickedButton<74>)
	ON_BN_CLICKED(IDC_BUTTON75, &CGame::OnBnClickedButton<75>)
	ON_BN_CLICKED(IDC_BUTTON76, &CGame::OnBnClickedButton<76>)
	ON_BN_CLICKED(IDC_BUTTON77, &CGame::OnBnClickedButton<77>)
	ON_BN_CLICKED(IDC_BUTTON78, &CGame::OnBnClickedButton<78>)
	ON_BN_CLICKED(IDC_BUTTON79, &CGame::OnBnClickedButton<79>)
	ON_BN_CLICKED(IDC_BUTTON80, &CGame::OnBnClickedButton<80>)
	ON_BN_CLICKED(IDC_BUTTON81, &CGame::OnBnClickedButton<81>)
END_MESSAGE_MAP()


// CGame 消息处理程序


template <int bid> void CGame::OnBnClickedButton()
{
	// TODO: 在此添加控件通知处理程序代码
	/*	测试更改文本的代码
	CString str;
	GetDlgItem(2700+bid)->GetWindowText(str);
	GetDlgItem(2700+bid)->SetWindowText(L"开启");
	*/
	//GetDlgItem(2700 + bid)->SetWindowText(L"开启");
	//CButton* ThisBTN = GetDlgItem(2700 + bid);
	//GetDlgItem(2700 + bid)->SetWindowText();

	//判断已选中两个能否交换
	if (!AlCh || AlCh == bid) {
		BTN[bid].SetState(1);
		AlCh = bid;
	}
	else {
		if (JudgeEx(AlCh, bid)) {
			BTN[bid].SetState(1);
			Exchange(BidtoX(AlCh), BidtoY(AlCh), BidtoX(bid), BidtoY(bid));
			AlCh = 0;
		}
		else {
			BTN[bid].SetState(1);
			Sleep(1000);
			BTN[AlCh].SetState(0);
			BTN[bid].SetState(0);
			AlCh = 0;
		}
	}


	//BTN[bid].SetFont();
}




BOOL CGame::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//Game_cwnd = this;

	// TODO:  在此添加额外的初始化
	PlaySound(_T("./res/GameOn.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	dre.seed(time(0));
	GMStart();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

//以下为Game Core

void ELM::SetType(int type) {
	ELMType = type;
}

void ELM::SetText(int text) {
	ELMText = text;
}

void ELM::SetStatus(int sta) {
	ELMStatus = sta;
}

void ELM::UpdateEid() {
	count++;
	Eid = count;
}

int ELM::GetEid() {
	return Eid;
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
	switch (ELMType) {
	case 2:Text = _T("←") + Text + _T("→"); break;	//横向特效
	case 3:Text = _T("↑") + Text + _T("↓"); break;	//纵向特效
	case 4:Text = _T("！") + Text + _T("！"); break;	//爆炸特效
	case 5:Text = "叮东"; break;	//寻找特效
	}
	return Text;
}

int ELM::GetType() {
	return ELMType;
}

int ELM::GetTextNum() {
	return ELMText;
}

int ELM::GetStatus() {
	return ELMStatus;
}

ELM* CGame::CreateELM(int text, int type) {
	if (!text) {
		text = uid(dre);
	}
	elm = new ELM();
	elm->SetType(type);
	elm->SetText(text);
	elm->UpdateEid();
	return elm;
}

void CGame::GMStart() {
	ifstart = 1;
	for (int i = 9; i >= 1; i--) {
		for (int j = 1; j <= 9; j++) {
			Pos[i][j] = CreateELM();
		}
	}
	//Load();
	Judge();
	ifstart = 0;
}

void CGame::Load() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			BTN[XYtoBid(i, j)].SetState(0);
			if(Pos[i][j]) GetDlgItem(2700 + XYtoBid(i, j))->SetWindowText(Pos[i][j]->GetText());
			else GetDlgItem(2700 + XYtoBid(i, j))->SetWindowText(L"");
		}
	}

}

void CGame::Exchange(int x1, int y1, int x2, int y2) {
	std::swap(Pos[x1][y1], Pos[x2][y2]);
	Pos[x1][y1]->UpdateEid();
	Pos[x2][y2]->UpdateEid();
	Load();
	int ChangeType = std::pow(Pos[x1][y1]->GetType(), 2) + std::pow(Pos[x2][y2]->GetType(), 2);
	switch (ChangeType) {
	case 2: case 5: case 10: case 17: { //普通交换
		if (!Judge()) {
			std::swap(Pos[x1][y1], Pos[x2][y2]);
			Load();
		}
	}
		  break;
	case 50: { //双寻找交换
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (1 != Pos[i][j]->GetType()) {
					Pos[i][j]->SetStatus(1);
				}
			}
		}
		Pos[x1][y1]->SetStatus(1);
		Pos[x2][y2]->SetStatus(1);
		Pos[x1][y1]->SetType(1);
		Pos[x2][y2]->SetType(1);
		while(Judge());
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				Pos[i][j]->SetStatus(1);
			}
		}
		Judge();
	}
		   break;
	case 26: { //单寻找交换
		int Text = 0;
		if (5 == Pos[x1][y1]->GetType()) Text = Pos[x2][y2]->GetTextNum();
		else Text = Pos[x1][y1]->GetTextNum();
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (Text == Pos[i][j]->GetTextNum()) {
					Pos[i][j]->SetStatus(1);
				}
			}
		}
		Pos[x1][y1]->SetStatus(1);
		Pos[x2][y2]->SetStatus(1);
		Pos[x1][y1]->SetType(1);
		Pos[x2][y2]->SetType(1);
		Judge();
	}
		   break;
	case 29: case 34: case 41: { //寻找特效交换
		int Text = 0;
		int Type = 0;
		if (5 == Pos[x1][y1]->GetType()) {
			Text = Pos[x2][y2]->GetTextNum();
			Type = Pos[x2][y2]->GetType();
		}
		else {
			Text = Pos[x1][y1]->GetTextNum();
			Type = Pos[x1][y1]->GetType();
		}
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (Text == Pos[i][j]->GetTextNum()) {
					Pos[i][j]->SetType(Type);
					Pos[i][j]->SetStatus(1);
				}
			}
		}
		Pos[x1][y1]->SetStatus(1);
		Pos[x2][y2]->SetStatus(1);
		Pos[x1][y1]->SetType(1);
		Pos[x2][y2]->SetType(1);
		Judge();
	}
		   break;
	case 8: case 13: case 18: { //横纵特效交换
		Pos[x1][y1]->SetStatus(1);
		Pos[x2][y2]->SetStatus(1);
		Judge();
	}
		   break;
	case 32: case 20: case 25: { //爆炸横纵交换
		int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0; //第1组为横纵特效，第二组为爆炸特效
		if (4 == Pos[x1][y1]->GetType()) {
			X1 = x2;
			Y1 = y2;
			X2 = x1;
			Y2 = y1;
		}
		else {
			X1 = x1;
			Y1 = y1;
			X2 = x2;
			Y2 = y2;
		}
		if (2 == Pos[X1][Y1]->GetType()) {
			for (int j = Y2 - 2; j <= Y2 + 2; j++) {
				for (int i = 1; i <= 9; i++) {
					if (j >= 1 && j <= 9) {
						Pos[i][j]->SetStatus(1);
					}
				}
			}
		}
		else {
			for (int i = X2 - 2; i <= X2 + 2; i++) {
				for (int j = 1; j <= 9; j++) {
					if (i >= 1 && i <= 9) {
						Pos[i][j]->SetStatus(1);
					}
				}
			}
		}
		Pos[x1][y1]->SetStatus(1);
		Pos[x2][y2]->SetStatus(1);
		Pos[x1][y1]->SetType(1);
		Pos[x2][y2]->SetType(1);
		Judge();
	}
		   break;
	}
}

void CGame::ClearELM(int x, int y) {
	delete Pos[x][y];
	Pos[x][y] = NULL;
}

void CGame::Fall() {
	int j = 1;
	while (j <= 9) {
		int i = 9;
		bool ifNoNULL = 1;
		while (i >= 1 && Pos[i][j] != NULL) i--;
		if (!i) {
			j++;
			continue;
		}
		while (NULL == Pos[i][j]) {
			for (int k = i; k >= 1; k--) {
				if (k == 1) {
					Pos[k][j] = CreateELM();
				}
				else {
					std::swap(Pos[k][j], Pos[k - 1][j]);
					if (Pos[k][j]) Pos[k][j]->UpdateEid();
				}
			}
		}
	}
}

bool CGame::Judge() {
	bool ifJudge = 0;
	int Text = 0;
	int JudgeCount = 0;
	int ContinueA[10] = { 0 };
	//先横向找
	for (int i = 9; i >= 1; i--) {
		for (int j = 1; j <= 7; j++) {
			Text = Pos[i][j]->GetTextNum();
			JudgeCount = 1;
			ContinueA[0] = XYtoBid(i, j);
			while (j + JudgeCount <= 9 && Text == Pos[i][j + JudgeCount]->GetTextNum()) {
				ContinueA[JudgeCount] = XYtoBid(i, j + JudgeCount);
				JudgeCount++;
			}
			if (JudgeCount >= 3) {
				ifJudge = 1;
				for (int k = 0; k < JudgeCount; k++) {
					Pos[BidtoX(ContinueA[k])][BidtoY(ContinueA[k])]->SetStatus(Pos[BidtoX(ContinueA[k])][BidtoY(ContinueA[k])]->GetStatus() + 1);
					if (!ifstart)
						BTN[ContinueA[k]].SetState(1);
				}
				if (!ifstart) {
					if (JudgeCount == 4) {
						int BidMax = FindMaxEid(ContinueA, JudgeCount);
						Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetStatus(-1);	//暂时更改为不可改变状态
						Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetType(3);	//变为纵向特效
					}
					if (JudgeCount >= 5) {
						int BidMax = FindMaxEid(ContinueA, JudgeCount);
						Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetStatus(-1);	//暂时更改为不可改变状态
						Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetType(5);	//变为寻找特效
					}
				}
				j += JudgeCount;
			}

		}
	}
	//再纵向找
	for (int j = 1; j <= 9; j++) {
		for (int i = 9; i >= 3; i--) {
			Text = Pos[i][j]->GetTextNum();
			JudgeCount = 1;
			ContinueA[0] = XYtoBid(i, j);
			while (i - JudgeCount >= 1 && Text == Pos[i - JudgeCount][j]->GetTextNum()) {
				ContinueA[JudgeCount] = XYtoBid(i - JudgeCount, j);
				JudgeCount++;
			}
			if (JudgeCount >= 3) {
				ifJudge = 1;
				for (int k = 0; k < JudgeCount; k++) {
					Pos[BidtoX(ContinueA[k])][BidtoY(ContinueA[k])]->SetStatus(Pos[BidtoX(ContinueA[k])][BidtoY(ContinueA[k])]->GetStatus() + 1);
					if (!ifstart) {
						//BTN[ContinueA[k]].SetState(1);
						if (2 == Pos[BidtoX(ContinueA[k])][BidtoY(ContinueA[k])]->GetStatus()) {
							int BidMax = FindMaxEid(ContinueA, JudgeCount);
							Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetStatus(-1);	//暂时更改为不可改变状态
							Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetType(4);	//变为爆炸特效
						}
					}
				}
				if (!ifstart) {
					if (JudgeCount == 4) {
						int BidMax = FindMaxEid(ContinueA, JudgeCount);
						Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetStatus(-1);	//暂时更改为不可改变状态
						Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetType(2);	//变为横向特效
					}
					if (JudgeCount >= 5) {
						int BidMax = FindMaxEid(ContinueA, JudgeCount);
						Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetStatus(-1);	//暂时更改为不可改变状态
						Pos[BidtoX(BidMax)][BidtoY(BidMax)]->SetType(5);	//变为寻找特效
					}
				}
				i -= JudgeCount;
			}

		}
	}

	/*	消除
	* 第一，找出所有状态为1（待消除）的ELM
	* 第二，触发其中的特效（即将指定范围内的ELM标记为1），休眠1秒
	* 第三，找出所有状态为1的ELM，删除元素，将指针置空NULL
	* 最后，找出所有状态为-1的ELM，状态改回0
	*/
	if (!ifstart) 
		FindTypeClear();
	Clear();
	Load();
	if(!ifstart) 
		Sleep(500);
	//下落
	Fall();

	//重置状态
	ResetStatus();
	Load();
	if (!ifstart)
		Sleep(500);

	if (ifJudge) 
		Judge();
	return ifJudge;
}

int CGame::BidtoX(int bid) {
	return (bid - 1) / 9 + 1;
}

int CGame::BidtoY(int bid) {
	if (bid % 9) return bid % 9;
	else return 9;
}

int CGame::XYtoBid(int x, int y) {
	return (x - 1) * 9 + y;
}

bool CGame::JudgeEx(int bid1, int bid2) {
	if ((BidtoX(bid1) == BidtoX(bid2)) && ((abs(BidtoY(bid1) - BidtoY(bid2)) == 1))) return 1;
	if ((BidtoY(bid1) == BidtoY(bid2)) && ((abs(BidtoX(bid1) - BidtoX(bid2)) == 1))) return 1;
	// TODO：此处还须添加寻找特效
	if (Pos[BidtoX(bid1)][BidtoY(bid1)]->GetType() == 5 || Pos[BidtoX(bid2)][BidtoY(bid2)]->GetType() == 5) return 1;
	return 0;
}

int CGame::FindMaxEid(int* array, int N) {
	int MaxBid = array[0];
	for (int i = 1; i < N; i++) {
		if (Pos[BidtoX(array[i])][BidtoY(array[i])]->GetEid() > Pos[BidtoX(MaxBid)][BidtoY(MaxBid)]->GetEid()) MaxBid = array[i];
	}
	return MaxBid;
}

void CGame::FindTypeClear() {
	bool iftype;
	do {
		iftype = 0;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (1 == Pos[i][j]->GetStatus()) {
					switch (Pos[i][j]->GetType()) {
					case 2:ClearType2(i, j); iftype = 1; break;
					case 3:ClearType3(i, j); iftype = 1; break;
					case 4:ClearType4(i, j); iftype = 1; break;
					case 5:ClearType5(i, j); iftype = 1; break;
					}
				}
			}
		}
		//选中即将被消除的元素
		//for (int i = 1; i <= 9; i++) {
		//	for (int j = 1; j <= 9; j++) {
		//		if (1 == Pos[i][j]->GetStatus()) 
		//			BTN[XYtoBid(i, j)].SetState(1);
		//	}
		//}
		//Sleep(1000);
	} while (iftype);
}

void CGame::Clear() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (1 == Pos[i][j]->GetStatus()) {
				ClearELM(i, j);
			}
		}
	}
}

void CGame::ClearType2(int x, int y) {
	Pos[x][y]->SetType(1);
	for (int j = 1; j <= 9; j++) {
		if (0 == Pos[x][j]->GetStatus()) Pos[x][j]->SetStatus(1);
	}
}

void CGame::ClearType3(int x, int y) {
	Pos[x][y]->SetType(1);
	for (int i = 1; i <= 9; i++) {
		if (0 == Pos[i][y]->GetStatus()) Pos[i][y]->SetStatus(1);
	}
}

void CGame::ClearType4(int x, int y) {
	Pos[x][y]->SetType(1);
	if (y - 2 >= 1) if (0 == Pos[x][y - 2]->GetStatus()) Pos[x][y - 2]->SetStatus(1);
	if (y - 1 >= 1) {
		if (x - 1 >= 1) if (0 == Pos[x - 1][y - 1]->GetStatus()) Pos[x - 1][y - 1]->SetStatus(1);
		if (0 == Pos[x][y - 1]->GetStatus()) Pos[x][y - 1]->SetStatus(1);
		if (x + 1 <= 9) if (0 == Pos[x + 1][y - 1]->GetStatus()) Pos[x + 1][y - 1]->SetStatus(1);
	}
	if (x - 1 >= 1) {
		if (0 == Pos[x - 1][y]->GetStatus()) Pos[x - 1][y]->SetStatus(1);
		if (x - 2 >= 1) if (0 == Pos[x - 2][y]->GetStatus()) Pos[x - 2][y]->SetStatus(1);
	}
	if (x + 1 <= 9) {
		if (0 == Pos[x + 1][y]->GetStatus()) Pos[x + 1][y]->SetStatus(1);
		if (x + 2 <= 9) if (0 == Pos[x + 2][y]->GetStatus()) Pos[x + 2][y]->SetStatus(1);
	}
	if (y + 1 <= 9) {
		if (x - 1 >= 1) if (0 == Pos[x - 1][y + 1]->GetStatus()) Pos[x - 1][y + 1]->SetStatus(1);
		if (0 == Pos[x][y + 1]->GetStatus()) Pos[x][y + 1]->SetStatus(1);
		if (x + 1 <= 9) if (0 == Pos[x + 1][y + 1]->GetStatus()) Pos[x + 1][y + 1]->SetStatus(1);
	}
	if (y + 2 >= 1) if (0 == Pos[x][y + 2]->GetStatus()) Pos[x][y + 2]->SetStatus(1);
}

void CGame::ClearType5(int x, int y) {
	Pos[x][y]->SetType(1);
	int Text = Pos[x][y]->GetTextNum();
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (Text == Pos[i][j]->GetTextNum()) Pos[i][j]->SetStatus(1);
		}
	}
}

void CGame::ResetStatus() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (-1 == Pos[i][j]->GetStatus()) Pos[i][j]->SetStatus(0);
		}
	}
}



