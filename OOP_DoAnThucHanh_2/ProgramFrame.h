#pragma once
#include<iostream>
using namespace std;

class ProgramFrame
{
protected:
	virtual void StartMessage(ostream &os);	
	virtual void Input(istream &is) = 0;
	virtual bool ValidData() = 0;
	virtual void ErrorMessage(ostream &os);
	virtual void Output(ostream &os) = 0;
	virtual void Processing() {};
	virtual bool AskToComtinue(istream &is, ostream &os);
public:
	ProgramFrame();
	void Run(istream &is, ostream &os);
	virtual void InputFile(istream &is) = 0;
	~ProgramFrame();
};

