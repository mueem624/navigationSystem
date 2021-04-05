/*
 * CGPSSensor.cpp
 *
 *  Created on: Nov 4, 2018
 *      Author: Mueem
 */




#include<iostream>
#include<limits>
#include<string>
#include "CGPSSensor.h"
#include"CWaypoint.h"

using namespace std;

CGPSSensor::CGPSSensor() {

}

//Implement getCurrentPosition function that user manually enter to get coordinates.
CWaypoint CGPSSensor::getCurrentPosition() {
	string name = " ";
	double latitude = 0.0, longitude = 0.0;
	cout << "Turning on GPS sensor" << endl;
	bool loop = true;
	while (loop) {

		// user manually input latitude via keyboard.
		cout << "Input your current latitude:  " << flush;
		cin >> latitude;
		// user manually input longitude via keyboard.
		cout << "Input your current longitude:  " << flush;
		cin >> longitude;
		if (longitude >= -180 && longitude <= 180 && latitude >= -90
				&& latitude <= 90) {
			loop = false;

		} else {
			cout << "Invalid Input\n";
		}
	}

	cout << endl;

	CWaypoint GPSWP("GPS location", latitude, longitude);
	return GPSWP;

}

CGPSSensor::~CGPSSensor() {
}
