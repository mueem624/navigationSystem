/*
 * CRoute.cpp
 *
 *  Created on: Nov 5, 2018
 *      Author: Mueem
 */


#include<iostream>
#include<string.h>
#include"CWaypoint.h"
#include"CPOI.h"
#include"CPoiDatabase.h"
#include "CRoute.h"

//Implement constructor
CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi) {

	m_nextWp = 0;
	m_maxWp = maxWp;
	// Implement dynamic array for m_pWaypoint to allocate memory to add waypoints
	m_pWaypoint = new CWaypoint[m_maxWp];

	m_nextPoi = 0;
	m_maxPoi = maxPoi;
	// Implement dynamic array for m_pPoi to allocate memory to add point of interest.
	m_pPoi = new CPOI*[m_maxPoi];
	m_pPoiDatabase = NULL;

}

//Implement copy constructor.
CRoute::CRoute(const CRoute& origin) {

	this->m_maxWp = origin.m_maxWp;
	this->m_nextWp = origin.m_nextWp;

//by using copy constructor to copying pointer of waypoints to the copy object from the original one .
	this->m_pWaypoint = new CWaypoint[origin.m_maxWp];

	for (unsigned int b = 0; b < origin.m_maxWp; b++) {

		m_pWaypoint[b] = origin.m_pWaypoint[b];
	}

	this->m_maxPoi = origin.m_maxPoi;
	this->m_nextPoi = origin.m_nextPoi;
//by using copy constructor to copying pointer of POI to the copy object from the original one.
	this->m_pPoi = new CPOI*[origin.m_maxPoi];

	for (unsigned int c = 0; c < origin.m_maxPoi; c++) {

		(this->m_pPoi)[c] = origin.m_pPoi[c];

	}

	this->m_pPoiDatabase = origin.m_pPoiDatabase;

}
// implement destructor to relase the memory allocated to the waypoint and poi;
CRoute::~CRoute() {

	delete[] m_pWaypoint;
	delete[] m_pPoi;

}
// Implement connectToPoiDatabase
void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB) {

	m_pPoiDatabase = pPoiDB;
}
//Implement addWaypoint for adding waypoint to CRoute;
void CRoute::addWaypoint(const CWaypoint& wp) {

	if (m_nextWp < m_maxWp) {

		m_pWaypoint[m_nextWp] = wp;
		m_nextWp++;
	} else {
		cerr << "Error: Already added maximum number of waypoint" << endl;
	}

}
//Implement addpoi function to add POI
void CRoute::addPoi(string namePoi) {

	if (m_pPoiDatabase != NULL) {
		if (m_nextPoi < m_maxPoi) {

			if (m_pPoiDatabase->getPointerToPoi(namePoi) != NULL) {

				m_pPoi[m_nextPoi] = (m_pPoiDatabase->getPointerToPoi(namePoi));
				m_nextPoi++;

			} else {
				cout << "there is no such point of interest in database"
						<< endl;

			}

		} else {
			cerr << "Maximum number of POI exceeded" << endl;
		}

	} else {
		cout << "Not connected to the database, empty database" << endl;
	}

}
// Implement getDistanceNextPoi function to calculate the distance for all POI and find the nearest distance
double CRoute::getDistanceNextPoi(const CWaypoint& wp, CPOI& poi) {

	int store;

	double nearestdist = 12345678.0;
	for (unsigned int d = 0; d < m_nextPoi; d++) {

		if (m_pPoi[d]->calculateDistance(wp) < nearestdist) {
			nearestdist = (m_pPoi[d]->calculateDistance(wp));

			store = d;
		}
	}
	cout << "distance to next POI= " << nearestdist << " km" << endl;
	m_pPoi[store]->print();

	return nearestdist;
}
//Implement print function.using cwaypoint print function to give the output as degree ,minute ,second;
void CRoute::print() {

	cout << "Our route has " << this->m_maxWp << " waypoints and "
			<< this->m_maxPoi << " Points of interest ." << endl;

	for (unsigned int W = 0; W < m_nextWp; W++) {
		m_pWaypoint[W].print(2);

	}

	for (unsigned int P = 0; P < m_nextPoi; P++) {
		m_pPoi[P]->print();
	}

}

