#include "Vehicle.h"



Vehicle::Vehicle()
{
	this->m_GPS.randInit();
	this->m_TypeOfVehicle = 0;
}


double Vehicle::getSpeed()
{
	return CRand::generateRandnNumab(20,50);
}

double Vehicle::getSpeed() const
{
	return CRand::generateRandnNumab(20,50);
}

status Vehicle::getSTT()
{
	return this->m_stt;
}

status Vehicle::getSTT() const
{
	return this->m_stt;
}

string Vehicle::getBrand()
{
	return this->m_strBrand;
}

string Vehicle::gteBrand() const
{
	return this->m_strBrand;
}

string Vehicle::getDriveName()
{
	return this->m_strDriveName;
}

string Vehicle::getDriveName() const
{
	return this->m_strDriveName;
}

string Vehicle::getNumberPlate()
{
	return this->m_strNumberPlate;
}

string Vehicle::getNumverPlate() const
{
	return this->m_strNumberPlate;
}

int Vehicle::getTypeOfVehicle()
{
	return this->m_TypeOfVehicle;
}

int Vehicle::getTypeOfVehicle() const
{
	return this->m_TypeOfVehicle;
}

void Vehicle::input(string strNumberPlate, string strDriveName, string strBrand, int info)
{
	this->m_strNumberPlate = strNumberPlate;
	this->m_strDriveName = strDriveName;
	this->m_strBrand = strBrand;
}


Vehicle::~Vehicle()
{
}
