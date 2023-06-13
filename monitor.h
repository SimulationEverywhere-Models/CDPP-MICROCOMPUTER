/*******************************************************************
*
*  DESCRIPTION: Atomic Model Monitor
*
*******************************************************************/

#ifndef __MONITOR_H
#define __MONITOR_H

#include <list>
#include "atomic.h"     // class Atomic

class Monitor : public Atomic
{
public:
	Monitor( const string &name = "Monitor" );					//Default constructor

	virtual string className() const ;
	double display; 
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft;

};	// class Monitor

// ** inline ** // 
inline
string Monitor::className() const
{
	return "Monitor" ;
}


#endif
