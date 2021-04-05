/*
 * CNavigationSystem.h
 *
 *  Created on: Nov 5, 2018
 *      Author: Mueem
 */

#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_
#include<iostream>
#include<string.h>
#include"CWaypoint.h"
#include"CPOI.h"
#include"CGPSSensor.h"
#include"CPoiDatabase.h"
#include"CRoute.h"

using namespace std;

//Declare CNavigationSystem class
class CNavigationSystem {

private:
// declare member attributes
	CGPSSensor m_GPSSensor;
	CRoute m_route;
	CPoiDatabase m_PoiDatabase;

	//Declare enterRoute function to enter the route with waypoints and point of interest.
	void enterRoute();
	//initialize printRoute function to print the route.
	void printRoute();
	//Declare printDistanceCurPosNextPoi function to get the nearest point of interest.
	void printDistanceCurPosNextPoi();

public:
	// Initialize constructor
	CNavigationSystem();
	//declare run function to run the navigation system
	void run();

};

#endif /* CNAVIGATIONSYSTEM_H_ */
