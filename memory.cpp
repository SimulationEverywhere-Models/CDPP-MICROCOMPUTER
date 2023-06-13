/*******************************************************************
*
*  DESCRIPTION: Atomic Model memory
*
*******************************************************************/

/** include files **/
#include "memory.h"      // class memory
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: memory
* Description: 
********************************************************************/
memory::memory( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, done( addInputPort( "done" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 0, 3 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: 
********************************************************************/
Model &memory::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &memory::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		elements.push_back( msg.value() ) ;
		if( elements.size() == 1 )
			holdIn( active, preparationTime );
	}

	if( msg.port() == done )
	{
		elements.pop_front() ;
		if( !elements.empty() )
			holdIn( active, preparationTime );
	}

	
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &memory::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &memory::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, elements.front() ) ;
	return *this ;
}
