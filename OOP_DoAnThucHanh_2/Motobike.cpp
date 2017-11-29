#include "Motobike.h"



Motobike::Motobike()
{
	this->m_TypeOfVehicle = motobike;
	this->m_dInitialPrice = 10000;
	this->m_dOver2kmPrice = 3500;
}

double Motobike::calcFare(double distance, double time)
{
	return this->m_dInitialPrice + m_dOver2kmPrice*this->calcKm(distance,2);
}

void Motobike::input(string strNumberPlate, string strDriveName, string strBrand, int info)
{
	Vehicle::input(strNumberPlate, strDriveName, strBrand, info);
}

void Motobike::output(ostream & os)
{
	os << "Motobike" << endl;
	Vehicle::output(os);
}


Motobike::~Motobike()
{
}
