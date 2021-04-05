/*
 * CPOI.cpp
 *
 *  Created on: Nov 4, 2018
 *      Author: Mueem
 */



#include<iostream>
#include<string.h>
#include "CPOI.h"
#include"CWaypoint.h"
using namespace std;

/*Implement CPOI constructor.
 * calling set function from CWaypoint as a inherited relationship with CPOI
 * Implementing attributes.
 */

CPOI::CPOI(t_poi type, string description, string name, double latitude,
		double longitude) :
		CWaypoint(name, latitude, longitude)

{

	m_type = type;
	m_description = description;
	set(name, latitude, longitude);

}

/*Implementing print method and calling print function
 *  from CWaypoint for printing point of interest's latitude and longitude
 *    as degree,minute,second.
 */

void CPOI::print() {

	switch (m_type) {

	case (BANK):
		cout << "point of interest " << endl << "=================" << endl
				<< "of type" << " Bank: " << m_description << endl;
		CWaypoint::print(2);
		break;

	case (GASSTATION):

		cout << "point of interest " << endl << "=================" << endl
				<< "of type" << " Gasstation: " << m_description << endl;
		CWaypoint::print(2);
		break;

	case (MUSEUM):

		cout << "point of interest " << endl << "=================" << endl
				<< "of type" << " Museum: " << m_description << endl;
		CWaypoint::print(2);
		break;

	case (RESTAURANT):

		cout << "point of interest " << endl << "=================" << endl
				<< "of type" << " Restaurant: " << m_description << endl;
		CWaypoint::print(2);
		break;
	case (CHURCH):

		cout << "point of interest " << endl << "=================" << endl
				<< "of type" << " Church: " << m_description << endl;
		CWaypoint::print(2);
		break;

	case (CINEPLEX):

		cout << "point of interest " << endl << "=================" << endl
				<< "of type" << " Cineplex: " << m_description << endl;
		CWaypoint::print(2);
		break;
	case (SHOPPINGMALL):

		cout << "point of interest " << endl << "=================" << endl
				<< "of type" << " Shoppingmall: " << m_description << endl;
		CWaypoint::print(2);
		break;

	case (NONE):

		cout << "point of interest " << endl << "=================" << endl
				<< " There is no point of interest " << m_description << endl;
		CWaypoint::print(2);
		break;
	default:
		break;

	}

}

//Implement getAllDataByReference function to get all data by pass by reference of parameters.
void CPOI::getAllDataByReference(string &name, double &latitude,
		double &longitude, t_poi &type, string &description) {

	type = m_type;
	description = m_description;
	name = getName();
	latitude = getLatitude();
	longitude = getLongitude();

}

CPOI::~CPOI() {
}
//
//CPOI::CPOI() {
//}
//
//CPOI::~CPOI() {
//	// TODO Auto-generated destructor stub
//}

