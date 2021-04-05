/*
 * CNavigationSystem.cpp
 *
 *  Created on: Nov 5, 2018
 *      Author: Mueem
 */

#include<iostream>
#include<string.h>
#include"CWaypoint.h"
#include "CNavigationSystem.h"
#include"CPOI.h"
#include"CGPSSensor.h"
#include"CPoiDatabase.h"
#include"CRoute.h"
//#define testcase

using namespace std;

// Implement empty constructor.
CNavigationSystem::CNavigationSystem() :
		m_route(3, 3)

{

}

////Implement enterRoute function to enter the route with waypoints and point of interest.
void CNavigationSystem::enterRoute() {

	//Test case for adding point of interest in database
	m_PoiDatabase.addPoi(BANK, "Good customer service", "Deutschebank",
			49.8726969, 8.6501009);
	m_PoiDatabase.addPoi(SHOPPINGMALL, "All in one market", "Weihnachtmarkt",
			49.8735023, 8.6531249);
	m_PoiDatabase.addPoi(CHURCH,
			"Terracotta designs and 450 years old church  ", "St.ludwig",
			49.8730297, 8.6507588);
	m_PoiDatabase.addPoi(GASSTATION, "24 hours open", "Jet", 49.8730291,
			8.6507588);
	m_PoiDatabase.addPoi(MUSEUM, "Museum of art and natur history",
			"landesmuseum", 49.8730284, 8.6507588);
	m_PoiDatabase.addPoi(RESTAURANT, "famous for Mexican food", "Hacienda",
			49.8634571, 8.6465531);
	m_PoiDatabase.addPoi(RESTAURANT, "Tasty food but expensive", "3klang",
			49.8807332, 8.6604964);
	m_PoiDatabase.addPoi(RESTAURANT, "The best kebab with affordable price ",
			"Ferrucci", 49.8783397, 8.6455372);
	m_PoiDatabase.addPoi(CINEPLEX, "famous for hollywood movies", "Kinopolis",
			49.8726219, 8.6337988);
	m_PoiDatabase.addPoi(RESTAURANT, "The best Mensa in the world", "Mensa",
			49.8614637, 8.6775388);

#ifdef testcase
	//Implement  testcase  point of interest to add more than maximum point of interest.

	m_PoiDatabase.addPoi(SHOPPINGMALL,"Best market for clothes ","luisencenter",49.872142,8.6494747);

#endif

//implement connectToPoiDatabase function
	m_route.connectToPoiDatabase(&m_PoiDatabase);

	// Implement addPoi function to add point of interest to route.
	m_route.addPoi("Deutschebank");
	m_route.addPoi("Weihnachtmarkt");
	//m_route.addPoi("St.ludwig");
	//m_route.addPoi("Jet");
	//m_route.addPoi("Hacienda");
	//m_route.addPoi("3klang");
	//m_route.addPoi("Ferrucci");
	//m_route.addPoi("Kinopolis");
	m_route.addPoi("Mensa");
	//m_route.addPoi("Landesmuseum");

#ifdef testcase
	/*// Implement addPoi function to add more point of interest to route,
	 * when the maximum number of point of interest already reached.
	 */

	m_route.addPoi("luisencenter");

#endif

	//Test case for adding waypoints.
	CWaypoint amsterdam("Amsterdam", 52.3667, 4.9000);
	CWaypoint darmstadt("Darmstadt", 49.872700, 8.65028);
	CWaypoint berlin("Berlin", 52.5243700, 13.41053);
	CWaypoint tokio("Tokio", 35.69100, 139.6921);

#ifdef testcase
	//Implement  testcase  waypoint to add more than maximum waypoint.
	CWaypoint stockholm("Stockholm", 59.334591, 18.063240);

#endif

	// Implement addwaypoint function to add Waypoint to route.
	m_route.addWaypoint(amsterdam);
	m_route.addWaypoint(darmstadt);
	m_route.addWaypoint(berlin);
	//m_route.addWaypoint(tokio);

	// Implement addwaypoint function to add more waypoint to route,when the maximum number of waypoint already reached.
#ifdef testcase
	m_route.addWaypoint(stockholm);
#endif
}

//Implement print route function to print the route
void CNavigationSystem::printRoute() {

	m_route.print();
}

////Implement printDistanceCurPosNextPoi function to get the nearest point of interest.
void CNavigationSystem::printDistanceCurPosNextPoi() {
	CWaypoint GPSWP = m_GPSSensor.getCurrentPosition();
	double lati, longi;
	lati = GPSWP.getLatitude();
	longi = GPSWP.getLongitude();

	if ((lati != 0) && (longi != 0)) {

		CPOI mypoi;

		m_route.getDistanceNextPoi(GPSWP, mypoi);
	} else {
		cerr
				<< "Error :Out of range latitude or longitude or both of coordinates ."
				<< endl;
	}

}

////Implement run function to run the navigation system
void CNavigationSystem::run() {
	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();

}
