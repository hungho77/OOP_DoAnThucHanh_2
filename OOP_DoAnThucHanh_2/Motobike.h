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
	virtual double calcFare(double distance, double time = 0);
	virtual void input(string strNumberPlate, string strDriveName, string strBrand, int info);
	virtual void output(ostream &os);
	virtual ~Motobike();
};

