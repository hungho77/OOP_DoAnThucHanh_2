#include "GoGo.h"
#include<cmath>
#include<iomanip>
#include<conio.h>
#include <io.h> // <- need to add this include for _setmode
#include <fcntl.h> // <- need to add this include for _O_TEXT
#include <cstdio> // <- need to add this include for wprintf
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
	system("cls");
	os << setw(48) << "" << "Welcome to GoGO booking!" << endl << endl;
}

void GoGo::Input(istream & is)
{
	cout << setw(20) << "" << right << setw(52) << left << "Enter star position (x, y) : ";
	is >> this->m_Start;
	cout << setw(20) << "" << right << setw(52) << left << "Enter finish position (x, y) : ";
	is >> this->m_Finish;
	cout << setw(20) << "" << right << setw(52) << left << "Enter type of vehicle (1.motobike/2.car/3.trunk) : ";
	is >> this->m_nTof;
	this->m_nSeat = 0;
	this->m_nLoad = 0;
	switch (this->m_nTof)
	{
	case motobike:
		break;
	case car:
		cout << setw(20) << "" << right << setw(52) << left << "Enter number seats: ";
		is >> m_nSeat;
		break;
	case trunk:
		cout << setw(20) << "" << right << setw(52) << left << "Enter vehicle load: ";
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
	if (   this->m_Start.getX() < -20  || this->m_Start.getX() > 20
		|| this->m_Start.getY() < -20  || this->m_Start.getY() > 20
		|| this->m_Finish.getX() < -20 || this->m_Finish.getX() > 20
		|| this->m_Finish.getY() < -20 || this->m_Finish.getY() > 20)
		return false;
	return true;
}

void GoGo::Output(ostream & os)
{

	os << setw(20) << " " << setfill('-') << setw(66) << "-" << endl;
	os << setfill(' ');
	os << setw(42) << "" << "Information of your vehicle booked" << endl;
	if (this->m_index == -1)
		os << setw(20) << "" << right << setw(52) << left << "Booking process failed!" << endl;
	else
	{
		this->m_pFlt.getElement(this->m_nTof - 1, this->m_index)->output(os);
		os << setw(20) << "" << right << setw(52) << left << "Time left: ";
		this->printTime(os);
		os << setw(20) << "" << right << setw(52) << left << "Fare: ";
		os << fixed << setprecision(2) << roundf(this->m_dFare * 100) / 100 << " VND" << endl;
	}
	cout << endl;
	os << setw(50) << "" << "Thank you customers!" << endl;
}

void GoGo::Processing()
{
	vector<int> index;
	for (int i = 0; i < this->m_pFlt.getN(this->m_nTof); i++)
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
		double distance = m_Start.calcDistance(this->m_pFlt.getElement(this->m_nTof - 1, index[i])->getGPS());
		if (minDistance > distance)
		{
			minDistance = distance;
			minDistanceIndex = index[i];
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
	index.empty();
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
	os << endl << setw(38) << "" << "Press 'Y' to continue, other key to stop...";
	ch = getch();
	return (ch == 'Y' || ch == 'y');
}

void GoGo::printTime(ostream &os)
{
	this->m_time *= 60;
	this->m_time = this->m_time;
	int hour = this->m_time / 3600;
	int minute = (this->m_time - hour * 3600) / 60;
	int second = this->m_time - hour * 3600 - minute * 60;
	os << hour << "h" << minute << "m" << second << "s" << endl;
}


void GoGo::display(ostream & os)
{
	cout << endl << endl << endl << endl << endl << endl << endl;
	_setmode(_fileno(stdout), 0x20000); // <- set the output mode to UTF-16
	wprintf(  // <- use wprintf to output UTF16 characters.
			  // note how the strings start with an 'L' prefix now

		L"                                   ▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄ \n"
		L"                                  ▐░░░░░░░░░░░▌ ▐░░░░░░░░░░░▌ ▐░░░░░░░░░░░▌ ▐░░░░░░░░░░░▌\n"
		L"                                  ▐░█▀▀▀▀▀▀▀▀▀  ▐░█▀▀▀▀▀▀▀█░▌ ▐░█▀▀▀▀▀▀▀▀▀  ▐░█▀▀▀▀▀▀▀█░▌\n"
		L"                                  ▐░▌           ▐░▌       ▐░▌ ▐░▌           ▐░▌       ▐░▌\n"
		L"                                  ▐░▌ ▄▄▄▄▄▄▄▄  ▐░▌       ▐░▌ ▐░▌ ▄▄▄▄▄▄▄▄  ▐░▌       ▐░▌\n"
		L"                                  ▐░▌▐░░░░░░░░▌ ▐░▌       ▐░▌ ▐░▌▐░░░░░░░░▌ ▐░▌       ▐░▌\n"
		L"                                  ▐░▌ ▀▀▀▀▀▀█░▌ ▐░▌       ▐░▌ ▐░▌ ▀▀▀▀▀▀█░▌ ▐░▌       ▐░▌\n"
		L"                                  ▐░▌       ▐░▌ ▐░▌       ▐░▌ ▐░▌       ▐░▌ ▐░▌       ▐░▌\n"
		L"                                  ▐░█▄▄▄▄▄▄▄█░▌ ▐░█▄▄▄▄▄▄▄█░▌ ▐░█▄▄▄▄▄▄▄█░▌ ▐░█▄▄▄▄▄▄▄█░▌\n"
		L"                                  ▐░░░░░░░░░░░▌ ▐░░░░░░░░░░░▌ ▐░░░░░░░░░░░▌ ▐░░░░░░░░░░░▌\n"
		L"                                   ▀▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀ \n"
		L"                                                                                      \n");
	_setmode(_fileno(stdout), _O_TEXT);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}


GoGo::~GoGo()
{

}
