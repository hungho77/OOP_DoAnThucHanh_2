#pragma once
#include"Vehicle.h"

class Car
	:public Vehicle
{
	//giá tối thiểu
	double m_dMinPrice;
	//giá mỗi kilomet
	double m_dPricePerKm;
	//số chỗ ngồi
	int m_nSeat;
	//giá thời gian di chuyển
	double m_dTimePrice;
public:
	Car();
	virtual void input(string strNumberPlate, string strDriveName, string strBrand, int info);
	virtual ~Car();
};

