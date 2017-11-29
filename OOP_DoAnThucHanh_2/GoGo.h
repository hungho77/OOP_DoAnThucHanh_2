#pragma once
#include"ProgramFrame.h"
#include"Fleet.h"
#include<queue>
struct UpdateInfo
{
	GPS finish;
	int i, j;
};

class GoGo:
	public ProgramFrame
{
	//đội xe
	Fleet m_pFlt;
	//tọa độ điểm khởi hành và điểm đến
	GPS m_Start, m_Finish;
	//loại phương tiên muốn gọi
	int m_nTof;
	//phương tiện khách yêu cầu
	int m_nSeat;
	int chooseSeat();
	int m_nLoad;
	int chooseLoad();
	//tiền cước
	double m_dFare;
	int m_index;
	double m_time;
	queue<UpdateInfo> m_update;
	//biến đếm số lượt gọi xe
	int m_count;
	void Input(istream &is);
	bool ValidData();
	void Output(ostream &os);
	void Processing();
	void update();
	virtual bool AskToComtinue(istream &is, ostream &os);
public:
	GoGo();
	void InputFile(istream &is);
	~GoGo();
};

