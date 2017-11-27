#include "ProgramFrame.h"



void ProgramFrame::StartMessage(ostream & os)
{
	os << "Welcome, entering data: ";
}

void ProgramFrame::ErrorMessage(ostream & os)
{
	os << "Input data error!" << endl;
}

bool ProgramFrame::AskToComtinue(istream & is, ostream & os)
{
	char ch;
	os << "Press 'Y' to continue, other key to stop...";
	is >> ch;
	return (ch == 'Y' || ch == 'y');
}

ProgramFrame::ProgramFrame()
{
}

void ProgramFrame::Run(istream & is, ostream & os)
{
	bool ToContinue;
	do 
	{
		StartMessage(os);
		Input(is);
		if (!ValidData())
		{
			ErrorMessage(os);
			continue;
		}
		Processing();
		Output(os);
		ToContinue = AskToComtinue(is, os);
	} while (ToContinue);
}


ProgramFrame::~ProgramFrame()
{
}
