#include "Fleet.h"


Fleet::Fleet()
{
	this->m_team = NULL;
	this->m_n = 0;
}

void Fleet::input(istream & is)
{
	is >> this->m_n;
	m_team = new Vehicle*[this->m_n];
	int type;
	string strNumberPlate;
	string strDriveName;
	string strBrand;
	int info;
	for (int i = 0; i < this->m_n; i++)
	{
		is >> type;
		switch (type)
		{
		case motobike:
			m_team[i] = new Motobike();
			break;
		case car:
			m_team[i] = new Car();
			break;
		case trunk:
			m_team[i] = new Trunk();
			break;
		default:
			break;
		}
		cin.ignore();
		getline(is, strNumberPlate);
		getline(is, strDriveName);
		getline(is, strBrand);
		is >> info;
		m_team[i]->input(strNumberPlate, strDriveName, strBrand, info);
	}
}

bool Fleet::isEmpty()
{
	if (this->m_team != NULL)
		return false;
	return true;
}

Vehicle * Fleet::operator[](int i)
{
	return this->m_team[i];
}

int Fleet::getN()
{
	return this->m_n;
}


Fleet::~Fleet()
{
	if (this->m_team != NULL)
	{
		for (int i = 0; i < this->m_n; i++)
		{
			if(this->m_team[i] != NULL)
			delete this->m_team[i];
		}
		delete[] this->m_team;
	}
}
