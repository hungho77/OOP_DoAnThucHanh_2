#include "Rand.h"
#include<iostream>
#include<ctime>
using namespace std;


CRand::CRand()
{
}

void CRand::initSeed()
{
	srand(time(NULL));
}

double CRand::generateRandnNumab(int a, int b)
{
	return rand() % (b - a) + a;
}


CRand::~CRand()
{
}
