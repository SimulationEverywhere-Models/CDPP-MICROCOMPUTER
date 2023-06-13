/*******************************************************************
*
*  DESCRIPTION: Atomic Model memory
*
*******************************************************************/

#ifndef __memory_H
#define __memory_H

#include <list>
#include "atomic.h"     // class Atomic

class memory : public Atomic
{
public:
	memory( const string &name = "memory" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	const Port &done;
	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft;

};	// class memory

// ** inline ** // 
inline
string memory::className() const
{
	return "memory" ;
}

#endif   //__memory_H
