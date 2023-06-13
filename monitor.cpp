/*******************************************************************
*
*  DESCRIPTION: Atomic Model Monitor
*
*******************************************************************/

/** include files **/
#include "monitor.h"      // class Monitor
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Monitor
* Description: 
********************************************************************/
Monitor::Monitor( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 0, 5 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: 
********************************************************************/
Model &Monitor::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Monitor::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		if ( state() != active )
		{
			display = msg.value();
			holdIn( active, preparationTime );
		}
	}
	
	
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Monitor::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Monitor::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, display ) ;
	return *this ;
}
