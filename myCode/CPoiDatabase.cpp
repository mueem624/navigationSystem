/*
 * CPoiDatabase1.cpp
 *
 *  Created on: Nov 4, 2018
 *      Author: Mueem
 */

#include<iostream>
#include<string.h>
#include"CWaypoint.h"
#include"CPOI.h"
#include "CPoiDatabase.h"
using namespace std;

//Implement constructor
CPoiDatabase::CPoiDatabase() {

// Implement m_noPoi function that count the total number of point of interest added in the database.
	m_noPoi = 0;
}

//Implement addpoi function to add point of interest in the database.
void CPoiDatabase::addPoi(t_poi type, string name, string description,
		double latitude, double longitude) {

	CPOI nwpoi(type, name, description, latitude, longitude);

	if (m_noPoi <= 9) {

		m_POI[m_noPoi] = nwpoi;
		m_noPoi++;
	} else {
		cerr << "Error: Database is full,unable to add more POI" << endl;
	}

}

//Implement getPointerToPoi function to search point of interest by given name.
CPOI* CPoiDatabase::getPointerToPoi(string name) {

	CPOI* pPoi;
	for (int k = 0; k < 10; k++) {

		if (m_POI[k].getName() == name) {

			pPoi = &m_POI[k];
			return pPoi;
		}

	}

	return 0;

}






