/*
 * CWaypoint.h
 *
 *  Created on: Nov 3, 2018
 *      Author: Mueem
 */
#include<iostream>
#include<stdlib.h>

using namespace std;

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_

//Declare class CWaypoint.
class CWaypoint {
protected:

	// Declare member attributes

	//string m_name:that is Waypoint name.
	string m_name;
	//double m_latitude:that is Waypoint latitude.
	double m_latitude;
	//double m_longitude:that is Waypoint longitude.
	double m_longitude;

private:

	//This function use to transform decimal longitude value to degree,minute and second.

	void transformLongitude2degmmss(int &deg, int &mm, double &ss);

	//This function use to transform decimal latitude value to degree,minute and second
	void transformLatitude2degmmss(int &deg, int &mm, double &ss);

public:

	//initializing constructor with default value.
	CWaypoint(string name = "No Name", double latitude = 0,
			double longitude = 0);

	//define set function that set the values.
	void set(string name, double latitude, double longitude);

	//declare get function to get the values of the function
	string getName();

	double getLatitude();

	double getLongitude();

	//define getAllDataByReference function.
	void getAllDataByReference(string &name, double &latitude,
			double &longitude);

	// define calculateDistance function to get the distance between two waypoints.
	double calculateDistance(const CWaypoint &wp);

	//using this function to get printing message  in decimal or degree,minute second.
	virtual void print(int format);

	virtual ~CWaypoint();
};

#endif /* CWAYPOINT_H_ */
