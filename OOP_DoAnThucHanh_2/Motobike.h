#pragma once
#include"Vehicle.h"

class Motobike
	:public Vehicle
{
	//giá ban đầu đi 2km đầu tiên
	double m_dInitialPrice;
	//giá sau 2km đầu tiên
	double m_dOver2kmPrice;
public:
	Motobike();
	virtual void input(string strNumberPlate, string strDriveName, string strBrand, int info);
	virtual ~Motobike();
};

