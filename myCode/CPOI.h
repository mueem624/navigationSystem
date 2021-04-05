/*
 * CPOI.h
 *
 *  Created on: Nov 4, 2018
 *      Author: Mueem
 */



#ifndef CPOI_H_
#define CPOI_H_


#include<iostream>
#include<string.h>

#include "CWaypoint.h"

//declare the type of point of interest
enum  t_poi{RESTAURANT,CINEPLEX,SHOPPINGMALL,MUSEUM,BANK,CHURCH,GASSTATION,NONE};
using namespace std;

//Initializing CPOI class and inherited with CWaypoint.Here CPOI act as a child class and CWaypoint act as a parent class.
class CPOI : public CWaypoint

{
	//declare member attributes to get the type and description of point of interest.
private:
	t_poi m_type;
	string m_description;

public:
	/* define print function to get type of POI,
	 * name of that POI,description,latitude and longitude
	 *  of that POI as a printing message.
	 */
	void print();

	//declare CPOI constructor and assign initial value .
	CPOI(t_poi type=NONE,string description="",string name="",double latitude=0, double longitude=0);

	//Initialize getAllDataByReference function to get all data by pass by reference of parameters.
	void getAllDataByReference (string &name,double &latitude, double &longitude,t_poi &type,string &description);
	 ~CPOI();
};

#endif /* CPOI_H_ */
