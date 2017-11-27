#include "Trunk.h"



Trunk::Trunk()
{
	this->m_TypeOfVehicle = trunk;
	this->m_nVehicleLoad = 0;
}

void Trunk::input(string strNumberPlate, string strDriveName, string strBrand, int info)
{
	this->input(strNumberPlate, strDriveName, strBrand, info);
	this->m_nVehicleLoad = info;
	switch (this->m_nVehicleLoad)
	{
	case 4:
		this->m_dTheOpenPrice = 300000;
		this->m_d11to44kmPrice = 14000;
		this->m_d45kmPrice = 13000;
		break;
	case 7:
		this->m_dTheOpenPrice = 400000;
		this->m_d11to44kmPrice = 15000;
		this->m_d45kmPrice = 14000;
		break;
	case 16:
		this->m_dTheOpenPrice = 500000;
		this->m_d11to44kmPrice = 20000;
		this->m_d45kmPrice = 17000;
		break;
	default:
		break;
	}
}


Trunk::~Trunk()
{
}
