#include<iostream>
#include<fstream>
#include"ProgramFrame.h"
#include"GoGo.h"
#include"Fleet.h"
#include"Rand.h"
#include"GPS.h"

int main()
{
	CRand::initSeed();
	ifstream inDevice;
	inDevice.open("input.txt");
	GoGo grab;
	grab.InputFile(inDevice);
	grab.Run(cin, cout);
	return 0;
}