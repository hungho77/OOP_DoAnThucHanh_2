#include "Car.h"
#include<iomanip>


Car::Car()
{
	this->m_TypeOfVehicle = car;
	this->m_nSeat = 0;
}

double Car::calcFare(double distance, double time)
{
	double fare = this->m_dPricePerKm*distance + this->m_dTimePrice*time;
	if (fare < this->m_dMinPrice)
		return this->m_dMinPrice;
	return fare;
}

int Car::get_nSeat()
{
	return this->m_nSeat;
}

int Car::get_nSeat() const
{
	return this->m_nSeat;
}

void Car::input(string strNumberPlate, string strDriveName, string strBrand, int info)
{
	Vehicle::input(strNumberPlate, strDriveName, strBrand, info);
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

void Car::output(ostream & os)
{
	os << setw(20) << "" << right << setw(52) << left << "Type of vehicle: " << "Car" << endl;
	Vehicle::output(os);
	os << setw(20) << "" << right << setw(52) << left << "Number of seats: " << this->m_nSeat << endl;
}


Car::~Car()
{
}
