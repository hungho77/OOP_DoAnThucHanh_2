#pragma once
#include "Vehicle.h"
class Trunk :
	public Vehicle
{
	//giá Giá mở cửa - 10km đầu
	double m_dTheOpenPrice;
	//giá Từ km thứ 11 đến 44
	double m_d11to44kmPrice;
	//giá Từ km thứ 45
	double m_d45kmPrice;	
	//trọng tải xe
	int m_nVehicleLoad;
public:
	Trunk();
	virtual void input(string strNumberPlate, string strDriveName, string strBrand, int info);
	virtual ~Trunk();
};

