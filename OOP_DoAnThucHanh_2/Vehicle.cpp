#include "Vehicle.h"
#include<iomanip>


double Vehicle::calcKm(double Km1, double Km2)
{
	double Km = Km1 - Km2;
	if (Km < 0)
		return 0;
	return Km;
}

Vehicle::Vehicle()
{
	this->m_GPS.randInit();
	this->m_TypeOfVehicle = 0;
	this->m_stt = leisured;
}

void Vehicle::setGPS(const GPS & x)
{
	this->m_GPS = x;
}

GPS Vehicle::getGPS()
{
	return this->m_GPS;
}

GPS Vehicle::getGPS() const
{
	return this->m_GPS;
}


double Vehicle::getSpeed()
{
	return CRand::generateRandnNumab(20,50);
}

double Vehicle::getSpeed() const
{
	return CRand::generateRandnNumab(20,50);
}

void Vehicle::setSTT(status x)
{
	this->m_stt = x;
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

string Vehicle::getBrand() const
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

int Vehicle::get_nSeat()
{
	return 0;
}

int Vehicle::get_nSeat() const
{
	return 0;
}

int Vehicle::get_nLoad()
{
	return 0;
}

int Vehicle::get_nLoad() const
{
	return 0;
}

void Vehicle::input(string strNumberPlate, string strDriveName, string strBrand, int info)
{
	this->m_strNumberPlate = strNumberPlate;
	this->m_strDriveName = strDriveName;
	this->m_strBrand = strBrand;

}

void Vehicle::output(ostream & os)
{
	os << setw(20) << "" << right << setw(52) << left << "Number plate: " << this->m_strNumberPlate << endl;
	os << setw(20) << "" << right << setw(52) << left << "Driver Name: " << this->m_strDriveName << endl;
	os << setw(20) << "" << right  << setw(52) << left << "Brand: " << this->m_strBrand << endl;
}


Vehicle::~Vehicle()
{
}
