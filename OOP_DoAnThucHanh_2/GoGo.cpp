#include "GoGo.h"
#include<cmath>
#include<iomanip>
using namespace std;

int GoGo::chooseSeat()
{
	if (this->m_nSeat < 1)
		return 0;
	if (this->m_nSeat < 5)
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

void GoGo::StartMessage(ostream & os)
{
	os << "Welcome to GoGO booking!" << endl;
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
		this->printTime(os);
		os << "Fare: ";
		os << fixed << setprecision(2) << roundf(this->m_dFare * 100) / 100 << " VND" << endl;
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
	double d = this->m_Start.calcDistance(this->m_Finish);

	this->m_time = 60 * (d / this->m_pFlt.getElement(this->m_nTof - 1, this->m_index)->getSpeed());
	this->m_dFare = this->m_pFlt.getElement(this->m_nTof - 1, this->m_index)->calcFare(d, this->m_time);
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
		this->m_pFlt.getElement(i, j)->setSTT(leisured);
		this->m_update.pop();
	}
}

bool GoGo::AskToComtinue(istream & is, ostream & os)
{
	this->m_count++;
	if (this->m_count == 5)
	{
		this->update();
		this->m_count = 0;
	}
	char ch;
	os << "Press 'Y' to continue, other key to stop...";
	is >> ch;
	return (ch == 'Y' || ch == 'y');

}

void GoGo::printTime(ostream &os)
{
	this->m_time *= 60;
	this->m_time = roundf(this->m_time * 1);
	int hour = this->m_time / 3600;
	int minute = roundf((this->m_time / 60 - hour * 60) * 1);
	int second = roundf((this->m_time - hour * 3600 - minute * 60) * 1);
	os << hour << "h" << minute << "m" << second << "s" << endl;
}

GoGo::~GoGo()
{

}
