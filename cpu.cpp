/*******************************************************************
*
*  DESCRIPTION: Atomic Model cpu
*
*******************************************************************/

/** include files **/
#include "cpu.h"      // class cpu
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: cpu
* Description: 
********************************************************************/
cpu::cpu( const string &name )
: Atomic( name )
, memory_in( addInputPort( "memory_in" ) )
, hd_done( addInputPort( "hd_done" ) )
, hd_out( addOutputPort( "hd_out" ) )
, monitor_out( addOutputPort( "monitor_out" ) )
, job_done( addOutputPort( "job_done" ) )
, preparationTime( 0, 0, 0, 10 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: 
********************************************************************/
Model &cpu::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &cpu::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == memory_in )
	{
		if ( msg.value() < 0 )
		{
			holdIn( active, preparationTime );
			this->sendOutput( msg.time(), hd_out, msg.value());
		}
		else
		{
			holdIn( active, preparationTime );
			this->sendOutput( msg.time(), monitor_out, msg.value());
			this->sendOutput( msg.time(), job_done, 0);
		}
		
	}

	if( msg.port() == hd_done )
	{
		holdIn( active, preparationTime );
		this->sendOutput( msg.time(), job_done, 1);
	}

	
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &cpu::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &cpu::outputFunction( const InternalMessage &msg )
{
	//sendOutput( msg.time(), out, elements.front() ) ;
	return *this ;
}
