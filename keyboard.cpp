/*******************************************************************
*
*  DESCRIPTION: Atomic Model Keyboard
*
*  DATE: Oct. 10, 2001
*
*******************************************************************/

/** include files **/
#include "keyboard.h"      // class Keyboard
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Keyboard
* Description: 
********************************************************************/
Keyboard::Keyboard( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 0, 1 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: 
********************************************************************/
Model &Keyboard::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Keyboard::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		
			
		if ( state() != active )
		{
			holdIn( active, preparationTime );
			keyvalue = msg.value();
		}
	}
	
	
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Keyboard::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Keyboard::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, keyvalue ) ;
	return *this ;
}
