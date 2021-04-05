/*
 * CRoute.h
 *
 *  Created on: Nov 5, 2018
 *      Author: Mueem
 */

#ifndef CROUTE_H_
#define CROUTE_H_
#include<iostream>
#include<string.h>
#include"CWaypoint.h"
#include"CPOI.h"
#include"CPoiDatabase.h"

using namespace std;

//declare CRoute class
class CRoute {

private:
	/**Declare member attributes.
	 * @supplierCardinality 0..*
	 * @clientCardinality 1
	 */

	//Declare m_pWaypoint attributes to get pointer to the memory block containing waypoints.
	CWaypoint* m_pWaypoint;
	//Declare maximum number of waypoints
	unsigned int m_maxWp;
	//define total number of waypoints added.
	unsigned int m_nextWp;
	//Declare m_pPoi attributes to get pointer to the memory block containing pointer to the point of interest.
	CPOI** m_pPoi;
	//Declare maximum number of point of interest that can be added.
	unsigned int m_maxPoi;
	//define total number of point of interest  added.
	unsigned int m_nextPoi;
	//declare pointer to the database.
	CPoiDatabase* m_pPoiDatabase;

public:

//Declare constructor and assign maximum waypoints and point of interest
	CRoute(unsigned int maxWp = 4, unsigned int maxPoi = 10);
//define copy constructor
	CRoute(CRoute const& origin);

//declare connectToPoiDatabase function
	void connectToPoiDatabase(CPoiDatabase* pPoiDB);
//declare addWaypoint function to add waypoint  to the pool of waypoints
	void addWaypoint(CWaypoint const& wp);
//declare addpoi function to add point of interest  to the pool of waypoints
	void addPoi(string namePoi);
//declare getDistanceNextPoi function to get the distance between waypoint and Point of interest.
	double getDistanceNextPoi(CWaypoint const& wp, CPOI &poi);
//declare print function to print the route.
	void print();









// using destructor to release the memory of member attributes.
	virtual ~CRoute();
};

#endif /* CROUTE_H_ */
