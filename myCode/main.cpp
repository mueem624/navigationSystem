//============================================================================
// Name        : main.cpp
// Author      :Md Muttayem Al Mueem
// Version     :1
// Copyright   : Your copyright notice
// Description : Navigation System in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#include"CWaypoint.h"
#include"CPOI.h"
#include "CNavigationSystem.h"
//#define SHOWDATA
using namespace std;

#define DEGREE 1
#define MMSS 2

int main(void) {

	CWaypoint amsterdam("Amsterdam", 52.3667, 4.9000);
	CWaypoint darmstadt("Darmstadt", 49.872700, 8.65028);
	CWaypoint berlin("Berlin", 52.5243700, 13.41053);
	CWaypoint tokio("Tokio", 35.69100, 139.6921);

#ifdef SHOWDATA
	berlin.print(DEGREE);
	berlin.print(MMSS);
#endif

#ifdef SHOWDATA
	amsterdam.getName();
	amsterdam.getLatitude();
	amsterdam.getLongitude();

	darmstadt.getName();
	darmstadt.getLatitude();
	darmstadt.getLongitude();

	berlin.getName();
	berlin.getLatitude();
	berlin.getLongitude();

	tokio.getName();
	tokio.getLatitude();
	tokio.getLongitude();
//using getAllDataByReference function to get all data of tokio in a single call
	string name;
	double latitude,longitude;
	tokio.getAllDataByReference(name,latitude,longitude);
	cout<<"Address of name: "<<&name<<endl<<"Address of latitude:  "<<&latitude<<endl<<"Address of longitude"<<endl;
	cout << "Name= "<<name<<endl<<"Latitude= "<<latitude<<endl<<"longitude"<<longitude<<endl;

	amsterdam.calculateDistance(berlin);
	cout<<"Distance between Amsterdam and Berlin: "<<amsterdam.calculateDistance(berlin)<<"km"<<endl;
	berlin.calculateDistance(tokio);
	cout<<"Distance between Berlin and tokio: "<<berlin.calculateDistance(tokio)<<"km"<<endl;
#endif

	CNavigationSystem navsys;
	navsys.run();

	return 0;
}
