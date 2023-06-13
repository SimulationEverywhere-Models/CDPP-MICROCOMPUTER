/*******************************************************************
*
*  DESCRIPTION: Atomic Model cpu
*
*******************************************************************/

#ifndef __cpu_H
#define __cpu_H

#include <list>
#include "atomic.h"     // class Atomic

class cpu : public Atomic
{
public:
	cpu( const string &name = "cpu" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &memory_in;
	const Port &hd_done;
	Port &hd_out;
	Port &monitor_out;
	Port &job_done;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft;

};	// class cpu

// ** inline ** // 
inline
string cpu::className() const
{
	return "cpu" ;
}

#endif   //__cpu_H
