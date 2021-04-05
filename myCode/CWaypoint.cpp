/*
 * CWaypoint.cpp
 *
 *  Created on: Nov 3, 2018
 *      Author: Mueem
 */
#include<iostream>
#include<math.h>

#include "CWaypoint.h"
//#define SHOWADDRESS
#define SHOWDATA
using namespace std;
/// \Create a instance of the CWaypoint class
/// \parameter name of the waypoint.
CWaypoint::CWaypoint(string name, double latitude, double longitude) {
//Using this method to store the parameter values of CWaypoint
	set(name, latitude, longitude);

#ifdef SHOWADDRESS

//Show the object name,latitude and longitude through 'this'pointer as an output.
	cout << "The name of the Object is: " << this->m_name << endl;
	cout << "The latitude of the Object is: " << this->m_latitude << endl;
	cout << "The longitude of the Object is: " << this->m_longitude << endl
	<< endl;

//Print the address of the object by using 'this'pointer as an output.
	cout << "Address for the name: " << &this->m_name << endl;
	cout << "Address for the latitude: " << &this->m_latitude << endl;
	cout << "Address for the longitude: " << &this->m_longitude << endl << endl;

// print the amount of data is possessed by using this function(sizeof) as an output.

	cout << sizeof(this->m_name) << " bytes memory is used for the name."
	<< endl;
	cout << sizeof(this->m_latitude)
	<< " bytes memory is used for the latitude." << endl;
	cout << sizeof(this->m_longitude)
	<< " bytes memory is used for the longitude." << endl << endl;

#endif

}

//Implement this function  to transform decimal latgitude value to degree,minute and second.
void CWaypoint::transformLatitude2degmmss(int &deg, int &mm, double &ss) {
	double minutefrac, x;
	int y, z, sum;

	deg = int(m_latitude);
	minutefrac = (m_latitude * 60) - (deg * 60);
	mm = int(minutefrac);
	x = m_latitude * 3600;
	y = deg * 3600;
	z = mm * 60;
	sum = y + z;
	ss = x - sum;

}

//Implement this function  to transform decimal longitude value to degree,minute and second.
void CWaypoint::transformLongitude2degmmss(int &deg, int &mm, double &ss) {

	deg = int(m_longitude);
	double minutefrac;
	minutefrac = (m_longitude * 60) - (deg * 60);
	mm = int(minutefrac);
	ss = (minutefrac * 60) - (mm * 60);

}

// Implement this function,that checks the parameter values are reachable or unreachable.
void CWaypoint::set(string name, double latitude, double longitude)

{
	m_name = name;
	// This condition is true ,writes latitude value to the attribute.
	if (latitude >= -90 && latitude <= 90) {
		m_latitude = latitude;

	}

	else {
		//This condition is true,get 0 as latitude value and writes latitude value to the attribute.
		m_latitude = 0;
		//invalid latitude, printing an error message.
		cerr << "Error:Latitude is unreachable" << endl;
	}

	// This condition is true ,writes longitude value to the attribute.
	if (longitude >= -180 && longitude <= 180) {
		m_longitude = longitude;

	}

	else {
		//This condition is true,get 0 as longitude value and writes longitude value to the attribute.
		m_longitude = 0;

		//invalid longitude printing an error message.
		cerr << "Error:Longitude is unreachable" << endl;
	}

}
// implement get function
string CWaypoint::getName() {

	return m_name;
}

double CWaypoint::getLatitude() {

	return m_latitude;
}

double CWaypoint::getLongitude() {
	return m_longitude;
}
//Implementing calculateDistance function to get the distance between two points.

double CWaypoint::calculateDistance(const CWaypoint &wp) {
	int R = 6378;
	double PI = 3.14159;
	double distance, a, b, c, x, y;

	a = sin((m_latitude * PI) / 180) * sin((wp.m_latitude * PI) / 180);
	b = cos((m_latitude * PI) / 180) * cos((wp.m_latitude * PI) / 180);
	x = ((wp.m_longitude * PI) / 180);
	y = ((m_longitude * PI) / 180);
	c = cos(x - y);

	distance = R * acos(a + (b * c));

	return distance;
}

//Implementing this function to get printing message  in decimal format or degree,minute second format.
void CWaypoint::print(int format) {

	//user can choose any format(1 or 2 ) and input the format number to get the output.

	if (0 < format && format < 3) {
		if (format == 1) {
			cout << m_name << " on latitude = " << m_latitude
					<< " and longitude = " << m_longitude << endl;
		} else {

			int deglat, deglong, mmlat, mmlong;
			double sslat, sslong;
			transformLatitude2degmmss(deglat, mmlat, sslat);
			transformLongitude2degmmss(deglong, mmlong, sslong);

			cout << m_name << " " << "on latitude=" << deglat << "deg "
					<< abs(mmlat) << "min " << fabs(sslat) << "s "
					<< "and longitude " << deglong << "deg " << (mmlong)
					<< "min " << fabs(sslong) << "s" << endl;
		}

	} else {
		cerr << "Error: Invalid user input" << endl;
	}

}
//Implement getAllDataByReference to get name,longitude and latitude.
void CWaypoint::getAllDataByReference(string& name, double& latitude,
		double& longitude) {
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;
}

CWaypoint::~CWaypoint() {
	// TODO Auto-generated destructor stub
}

