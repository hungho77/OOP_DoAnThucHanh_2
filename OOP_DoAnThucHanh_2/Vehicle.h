#pragma once
#include"GPS.h"
#include<iostream>
#include<string>
using namespace std;
#define motobike 1
#define car 2
#define trunk 3

//trạng thái của xe(rảnh rổi hoặc bận)
enum status{free, busy};

class Vehicle
{
protected:
	//tọa độ của xe
	GPS m_GPS;
	//trạng thái của xe (đang rảnh hoặc đang bận)
	status m_stt;
	//thương hiệu xe
	string m_strBrand;
	//tên tài xế
	string m_strDriveName;
	//biển số xe
	string m_strNumberPlate;
	//loại xe 
	int m_TypeOfVehicle;
public:
	Vehicle();
	double getSpeed();
	double getSpeed() const;
	status getSTT();
	status getSTT() const;
	string getBrand();
	string gteBrand() const;
	string getDriveName();
	string getDriveName() const;
	string getNumberPlate();
	string getNumverPlate() const;
	virtual int getTypeOfVehicle();
	virtual int getTypeOfVehicle() const;
	virtual void input(string strNumberPlate, string strDriveName, string strBrand, int info);
	virtual ~Vehicle();
};

