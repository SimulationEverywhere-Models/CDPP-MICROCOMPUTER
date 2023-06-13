/*******************************************************************
*
*  DESCRIPTION: Atomic Model Harddisk
*
*  DATE: Oct. 10, 2001
*
*******************************************************************/

/** include files **/
#include "harddisk.h"      // class Harddisk
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Harddisk
* Description: 
********************************************************************/
Harddisk::Harddisk( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, done( addOutputPort( "done" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 0, 20 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description:  
********************************************************************/
Model &Harddisk::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Harddisk::externalFunction( const ExternalMessage &msg )
{
	
	
	if( msg.port() == in )
	{
		if ( state() != active )
		{
			data = msg.value();
			holdIn( active, preparationTime );
		}
	}
	
	
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Harddisk::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Harddisk::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, data );
	sendOutput( msg.time(), done, 0) ;
	return *this ;
}
