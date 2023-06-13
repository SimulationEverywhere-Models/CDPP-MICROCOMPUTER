/*******************************************************************
*
*  DESCRIPTION: Atomic Model Keyboard
*
*******************************************************************/

#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include <list>
#include "atomic.h"     // class Atomic

class Keyboard : public Atomic
{
public:
	Keyboard( const string &name = "Keyboard" );					//Default constructor

	virtual string className() const ;
	double keyvalue; 
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

};	// class Keyboard

// ** inline ** // 
inline
string Keyboard::className() const
{
	return "Keyboard" ;
}


#endif
