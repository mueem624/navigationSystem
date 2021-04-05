/*
 * CPoiDatabase.h
 *
 *  Created on: Nov 4, 2018
 *      Author: Mueem
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_
#include<iostream>
#include<string.h>
#include"CWaypoint.h"
#include"CPOI.h"
using namespace std;

// Declare CPoiDatabase class,which contains point of interest.
class CPoiDatabase {

private:
	/**
	 * @link aggregationByValue
	 * @supplierCardinality 1..10
	 */

	//Define member attributes that contains maximum number of 10 point of interest.
	CPOI m_POI[10];
	//Total number of point of interest added in the database.
	int m_noPoi;
public:

	//declare CPoiDatabase constructor.
	CPoiDatabase();
	//declare addpoi function to add point of interest in the database.
	void addPoi(t_poi type, string name, string description, double latitude,
			double longitude);

	//Declare getPointerToPoi function to search point of interest by given name.
	CPOI* getPointerToPoi(string name);
};

#endif /* CPOIDATABASE_H_ */



