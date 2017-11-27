#pragma once
#include"ProgramFrame.h"
#include"Fleet.h"
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
	int m_nLoad;
	//tiền cước
	double m_dFare;
public:
	GoGo(Fleet pFlt);
	void Input(istream &is);
	bool ValidData();
	void Output(ostream &os);
	void Processing();
	~GoGo();
};

