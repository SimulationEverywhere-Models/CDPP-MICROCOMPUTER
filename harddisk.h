/*******************************************************************
*
*  DESCRIPTION: Atomic Model Harddisk
*
*  DATE: Oct. 10, 2001
*
*******************************************************************/

#ifndef __HARDDISK_H
#define __HARDDISK_H

#include <list>
#include "atomic.h"     // class Atomic

class Harddisk : public Atomic
{
public:
	Harddisk( const string &name = "Harddisk" );					//Default constructor

	virtual string className() const ;
	 
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	Port &done;
	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;
	float data;

	Time timeLeft;

};	// class Harddisk

// ** inline ** // 
inline
string Harddisk::className() const
{
	return "Harddisk" ;
}


#endif
