/*
 * CGPSSensor.h
 *
 *  Created on: Nov 4, 2018
 *      Author: Mueem
 */

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_
#include"CWaypoint.h"
using namespace std;

//Declare CGPSSensor class
class CGPSSensor {

private:

public:

	//declare constructor and public methods.
	CGPSSensor();

	//declare getCurrentPosition function.
	CWaypoint getCurrentPosition();

public:

	virtual ~CGPSSensor();
};

#endif /* CGPSSENSOR_H_ */

