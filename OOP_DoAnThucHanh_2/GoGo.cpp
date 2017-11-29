#include "GoGo.h"



int GoGo::chooseSeat()
{
	if (this->m_nSeat < 1)
		return 0;
	if (this->m_nSeat <= 4)
		return 4;
	if (this->m_nSeat < 8)
		return 7;
	if (this->m_nSeat < 17)
		return 16;
	return 0;
}

int GoGo::chooseLoad()
{
	if (this->m_nLoad < 1)
		return 0;
	if (this->m_nLoad < 750)
		return 750;
	if (this->m_nLoad < 1500)
		return 1500;
	if (this->m_nLoad < 1900)
		return 1900;
	return 0;
}

GoGo::GoGo()
{
	this->m_nTof = 0;
	this->m_nSeat = 0;
	this->m_nLoad = 0;
	this->m_count = 0;
	this->m_time = 0;
	this->m_dFare = 0;
	this->m_index = 0;
}

void GoGo::InputFile(istream & is)
{
	m_pFlt.input(is);
}

void GoGo::Input(istream & is)
{
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
	if (this->m_index == -1)
		os << "Booking process failed!" << endl;
	else
	{
		this->m_pFlt.getElement(this->m_nTof - 1, this->m_index)->output(os);
		os << "Time left: ";
		os << this->m_time << " minutes" << endl;
		os << "Fare: ";
		os << this->m_dFare << " VND" << endl;
	}
	os << "Thank you customers!" << endl;
}

void GoGo::Processing()
{
	vector<int> index;
	for (int i = 0; i < this->m_pFlt.getN(m_nTof); i++)
	{
		if (this->m_pFlt.getElement(this->m_nTof - 1, i)->getSTT() == leisured
			&& this->m_pFlt.getElement(this->m_nTof - 1, i)->get_nSeat() == chooseSeat()
			&& this->m_pFlt.getElement(this->m_nTof - 1, i)->get_nLoad() == chooseLoad())
			index.push_back(i);
	}
	int minDistanceIndex = -1;
	double minDistance = double(INT_MAX);
	for (int i = 0; i < index.size(); i++)
	{
		double distance = m_Start.calcDistance(this->m_pFlt.getElement(this->m_nTof - 1, i)->getGPS());
		if (minDistance > distance)
		{
			minDistance = distance;
			minDistanceIndex = i;
		}
	}

	this->m_index = minDistanceIndex;
	if (this->m_index == -1)
		return;
	double d = this->m_Start.calcDistance(this->m_Finish) ;
	
	this->m_time = d /  this->m_pFlt.getElement(this->m_nTof - 1, this->m_index)->getSpeed();
	this->m_dFare = this->m_pFlt.getElement(this->m_nTof - 1, this->m_index)->calcFare(d,this->m_time);
	this->m_pFlt.getElement(this->m_nTof - 1, this->m_index)->setSTT(busy);
	//lưu thông tin để cập nhật
	UpdateInfo x;
	x.finish = this->m_Finish;
	x.i = this->m_nTof - 1;
	x.j = this->m_index;
	this->m_update.push(x);
}

void GoGo::update()
{
	int i, j;
	while (!this->m_update.empty())
	{
		i = this->m_update.front().i;
		j = this->m_update.front().j;
		this->m_pFlt.getElement(i, j)->setGPS(this->m_update.front().finish);
		this->m_update.pop();
	}
}

bool GoGo::AskToComtinue(istream & is, ostream & os)
{
	this->m_count++;
	if (this->m_count == 5)
	{
		this->update();
	}
	char ch;
	os << "Press 'Y' to continue, other key to stop...";
	is >> ch;
	return (ch == 'Y' || ch == 'y');
	
}


GoGo::~GoGo()
{
}
