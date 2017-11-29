#pragma once
#include"Car.h"
#include"Motobike.h"
#include"Trunk.h"
#include"Vehicle.h"
#include<vector>

//đội xe
class Fleet
{
	Vehicle ***m_team;
	//số loại xe
	int m_m;
	//mảng lưu trữ số lượng xe và mỗi loại
	//(0: số lượng xe tất cả, 1: số lượng xe máy, 2: số lượng xe hơi, 3: số lượng xe tải)
	int *m_n;
public:
	Fleet();
	void input(istream &is);
	bool isEmpty();
	Vehicle *&getElement(int i, int j);
	int getN(int i);
	~Fleet();
};

