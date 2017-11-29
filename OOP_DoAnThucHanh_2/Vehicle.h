#pragma once
#include"GPS.h"
#include<iostream>
#include<string>
using namespace std;
#define motobike 1
#define car 2
#define trunk 3

//trạng thái của xe(rảnh rổi hoặc bận)
enum status{leisured, busy};

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
	//
	double calcKm(double Km1, double Km2);
public:
	Vehicle();
	virtual double calcFare(double distance, double time = 0) = 0;
	void setGPS(const GPS &x);
	GPS getGPS();
	GPS getGPS() const;
	double getSpeed();
	double getSpeed() const;
	void setSTT(status x);
	status getSTT();
	status getSTT() const;
	string getBrand();
	string getBrand() const;
	string getDriveName();
	string getDriveName() const;
	string getNumberPlate();
	string getNumverPlate() const;
	virtual int getTypeOfVehicle();
	virtual int getTypeOfVehicle() const;
	virtual int get_nSeat();
	virtual int get_nSeat() const;
	virtual int get_nLoad();
	virtual int get_nLoad() const;
	virtual void input(string strNumberPlate, string strDriveName, string strBrand, int info);
	virtual void output(ostream &os);
	virtual ~Vehicle();
};

