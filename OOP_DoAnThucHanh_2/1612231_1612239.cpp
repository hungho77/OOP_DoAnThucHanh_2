#include<iostream>
#include<fstream>
#include"ProgramFrame.h"
#include"GoGo.h"
#include"Fleet.h"
#include"Rand.h"
#include"GPS.h"
int main()
{
	system("color A");
	CRand::initSeed();
	ifstream inDevice;
	inDevice.open("input.txt");
	ProgramFrame *grab = new GoGo();
	grab->display(cout);
	system("pause");
	system("cls");
	grab->InputFile(inDevice);
	grab->Run(cin, cout);
	delete grab;
	cout << endl;
	return 0;
}