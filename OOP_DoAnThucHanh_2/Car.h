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
	virtual double calcFare(double distance, double time = 0);
	virtual int get_nSeat();
	virtual int get_nSeat() const;
	virtual void input(string strNumberPlate, string strDriveName, string strBrand, int info);
	virtual void output(ostream &os);
	virtual ~Car();
};

