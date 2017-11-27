#pragma once
#include"Car.h"
#include"Motobike.h"
#include"Trunk.h"
#include"Vehicle.h"

//đội xe
class Fleet
{
	Vehicle **m_team;
	//số lượng xe
	int m_n;
public:
	Fleet();
	void input(istream &is);
	bool isEmpty();
	Vehicle* operator [](int i);
	int getN();
	~Fleet();
};

