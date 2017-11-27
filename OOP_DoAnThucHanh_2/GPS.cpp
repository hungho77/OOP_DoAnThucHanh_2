#include "GPS.h"



GPS::GPS()
{
	this->m_nX = this->m_nY = 0;
}

GPS::GPS(double x, double y)
{
	if (x < -20 || x>20 || y < -20 || y>20)
		_DEBUG_ERROR("out of range");
	else
	{
		this->m_nX = x;
		this->m_nY = y;
	}
}

double GPS::getX()
{
	return this->m_nX;
}

double GPS::getX() const
{
	return this->m_nX;
}

double GPS::getY()
{
	return this->m_nY;
}

double GPS::getY() const
{
	return this->m_nY;
}

double GPS::calcDistance(const GPS & a)
{
	return sqrt((this->m_nX - a.m_nX)*(this->m_nX - a.m_nX) + (this->m_nY - a.m_nY)*(this->m_nY - a.m_nY));
}

void GPS::randInit()
{
	this->m_nX = CRand::generateRandnNumab(-20, 20);
	this->m_nY = CRand::generateRandnNumab(-20, 20);
}


GPS::~GPS()
{
}

istream & operator >> (istream & is, GPS & pos)
{
	is >> pos.m_nX >> pos.m_nY;
	return is;
}
