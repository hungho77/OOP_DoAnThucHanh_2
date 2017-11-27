#pragma once

class CRand
{
public:
	CRand();
	static void initSeed();
	static double generateRandnNumab(int a, int b);
	~CRand();
};

