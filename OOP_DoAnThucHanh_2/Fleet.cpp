#include "Fleet.h"

Fleet::Fleet()
{
	this->m_team = NULL;
	this->m_m = 3;
	this->m_n = new int[4]{ 0 };
}

void Fleet::input(istream & is)
{
	is >> this->m_n[0];
	this->m_team = new Vehicle**[this->m_m];
	for (int i = 0; i < this->m_m; i++)
		this->m_team[i] = new Vehicle *[this->m_n[0]];
	int type;
	string strNumberPlate;
	string strDriveName;
	string strBrand;
	int info;
	for (int i = 0, j = 0, k = 0, l = 0; i < this->m_n[0]; i++)
	{
		is >> type;
		switch (type)
		{
		case motobike:
			m_team[type - 1][j] = new Motobike();
			is.ignore();
			getline(is, strNumberPlate);
			getline(is, strDriveName);
			getline(is, strBrand);
			is >> info;
			m_team[type - 1][j]->input(strNumberPlate, strDriveName, strBrand, info);
			this->m_n[motobike]++;
			j++;
			break;
		case car:
			m_team[type - 1][k] = new Car();
			is.ignore();
			getline(is, strNumberPlate);
			getline(is, strDriveName);
			getline(is, strBrand);
			is >> info;
			m_team[type - 1][k]->input(strNumberPlate, strDriveName, strBrand, info);
			this->m_n[car]++;
			k++;
			break;
		case trunk:
			m_team[type - 1][l] = new Trunk();
			is.ignore();
			getline(is, strNumberPlate);
			getline(is, strDriveName);
			getline(is, strBrand);
			is >> info;
			m_team[type - 1][l]->input(strNumberPlate, strDriveName, strBrand, info);
			this->m_n[trunk]++;
			l++;
			break;
		default:
			break;
		}
	}
}

bool Fleet::isEmpty()
{
	if (this->m_team != NULL)
		return false;
	return true;
}

Vehicle *&Fleet::getElement(int i, int j)
{
	return this->m_team[i][j];
}

int Fleet::getN(int i)
{
	return this->m_n[i];
}


Fleet::~Fleet()
{
	if (this->m_team != NULL)
	{
		for (int i = 0; i < this->m_m; i++)
		{
			for (int j = 0; j < this->m_n[i+1]; j++)
			{
				if (this->m_team[i][j] != NULL)
					delete this->m_team[i][j];
			}
			delete[] this->m_team[i];
		}
		delete this->m_team;
	}
	delete[] this->m_n;
}
