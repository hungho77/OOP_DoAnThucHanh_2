#include "Trunk.h"



Trunk::Trunk()
{
	this->m_TypeOfVehicle = trunk;
	this->m_nVehicleLoad = 0;
}

double Trunk::calcFare(double distance, double time)
{
	if (distance < 45)
		return this->m_dTheOpenPrice + this->m_d11to44kmPrice*this->calcKm(distance, 10);
	return this->m_dTheOpenPrice + this->m_d11to44kmPrice*this->calcKm(44, 10) + this->m_d45kmPrice*this->calcKm(distance, 45);
}

int Trunk::get_nLoad()
{
	return this->m_nVehicleLoad;
}

int Trunk::get_nLoad() const
{
	return this->m_nVehicleLoad;
}

void Trunk::input(string strNumberPlate, string strDriveName, string strBrand, int info)
{
	Vehicle::input(strNumberPlate, strDriveName, strBrand, info);
	this->m_nVehicleLoad = info;
	switch (this->m_nVehicleLoad)
	{
	case 750:
		this->m_dTheOpenPrice = 300000;
		this->m_d11to44kmPrice = 14000;
		this->m_d45kmPrice = 13000;
		break;
	case 1500:
		this->m_dTheOpenPrice = 400000;
		this->m_d11to44kmPrice = 15000;
		this->m_d45kmPrice = 14000;
		break;
	case 1900:
		this->m_dTheOpenPrice = 500000;
		this->m_d11to44kmPrice = 20000;
		this->m_d45kmPrice = 17000;
		break;
	default:
		break;
	}
}

void Trunk::output(ostream & os)
{
	os << "Trunk" << endl;
	Vehicle::output(os);
	if (this->m_nVehicleLoad == 750)
		os << this->m_nVehicleLoad << "kg" << endl;
	else
	{
		os << this->m_nVehicleLoad / 1000.0 << "ton" << endl;
	}
}


Trunk::~Trunk()
{
}
