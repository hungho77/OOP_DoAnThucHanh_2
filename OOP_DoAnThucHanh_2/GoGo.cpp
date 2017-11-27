#include "GoGo.h"



GoGo::GoGo(Fleet pFlt)
{
	this->m_pFlt = pFlt;
}

void GoGo::Input(istream & is)
{
	m_pFlt.input(is);
	cout << "Enter star position: ";
	is >> this->m_Start;
	cout << "Enter finish position: ";
	is >> this->m_Finish;
	cout << "Enter type of vehicle (1.motobike/2.car/3.trunk): ";
	is >> this->m_nTof;
	switch (this->m_nTof)
	{
	case motobike:
		break;
	case car:
		is >> m_nSeat;
		break;
	case trunk:
		is >> m_nLoad;
		break;
	default:
		break;
	}
}

bool GoGo::ValidData()
{
	if (this->m_nTof > 3 || this->m_nTof < 1 || m_pFlt.isEmpty())
		return false;
	return true;
}

void GoGo::Output(ostream & os)
{
	os << "Thank you customers!" << endl;
}

void GoGo::Processing()
{
	for (int i = 0; i < this->m_pFlt.getN(); i++)
	{
		this->m_pFlt[i]->getTypeOfVehicle
	}
}


GoGo::~GoGo()
{
}
