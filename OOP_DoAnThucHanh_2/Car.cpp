#include "Car.h"



Car::Car()
{
	this->m_TypeOfVehicle = car;
	this->m_nSeat = 0;
}

void Car::input(string strNumberPlate, string strDriveName, string strBrand, int info)
{
	this->input(strNumberPlate, strDriveName, strBrand, info);
	this->m_nSeat = info;
	switch(this->m_nSeat)
	{
	case 4:
		this->m_dMinPrice = 20000;
		this->m_dPricePerKm = 9000;
		this->m_dTimePrice = 300; 
		break;
	case 7:
		this->m_dMinPrice = 24000;
		this->m_dPricePerKm = 11000;
		this->m_dTimePrice = 300;
		break;
	case 16:
		this->m_dMinPrice = 30000;
		this->m_dPricePerKm = 15000;
		this->m_dTimePrice = 400;
		break;
	default:
		break;
	}
}


Car::~Car()
{
}
