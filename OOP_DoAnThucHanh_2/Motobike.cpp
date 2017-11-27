#include "Motobike.h"



Motobike::Motobike()
{
	this->m_TypeOfVehicle = motobike;
	this->m_dInitialPrice = 10000;
	this->m_dOver2kmPrice = 3500;
}

void Motobike::input(string strNumberPlate, string strDriveName, string strBrand, int info)
{
	this->input(strNumberPlate, strDriveName, strBrand, info);
}


Motobike::~Motobike()
{
}
