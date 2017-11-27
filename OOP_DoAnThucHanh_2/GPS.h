#pragma once
#include"Rand.h"
#include<iostream>
#include<cmath>
using namespace std;

class GPS
{
	double m_nX;
	double m_nY;
public:
	GPS();
	GPS(double x, double y);
	double getX();
	double getX() const;
	double getY();
	double getY() const;
	double calcDistance(const GPS &a);
	void randInit();
	friend istream &operator >> (istream &is, GPS &pos);
	~GPS();
};

