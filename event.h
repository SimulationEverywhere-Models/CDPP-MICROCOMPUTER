/*******************************************************************
*
*  DESCRIPTION: struct Event
*
*  AUTHOR:    Amir Barylko & Jorge Beyoglonian 
*  Version 2: Daniel Rodriguez
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*         mailto://drodrigu@dc.uba.ar
*
*  DATE: 27/06/1998
*  DATE: 11/10/1998 (v2)
*
*******************************************************************/

#ifndef __EVENT_H
#define __EVENT_H

/** include files **/
#include "time.h"    // class Time
#include "real.h"	// class Real
#include "port.h"       // class Port

/** foward declarations **/

/** definitions **/
struct Event
{
	Time time ;
	const Port *port ;
	Real value ;

	Event( const Time = Time::Zero, const Port * = NULL, const Real = Real(0) );

	bool operator < ( const Event &ev )
		{return time < ev.time;}
		
	Event &operator =( const Event &ev ) ;

	const string asString() const
		{return time.asString() + " / " + port->asString() + " / " + value.asString();}
} ;


/** inline methods **/
inline
Event::Event( const Time t, const Port *p , const Real v)
: time( t )
, port( p )
, value( v )
{}

inline
Event &Event::operator =( const Event &ev )
{
	time = ev.time ;
	port = ev.port ;
	value = ev.value ;
	return *this;
}

#endif   //__EVENT_H
