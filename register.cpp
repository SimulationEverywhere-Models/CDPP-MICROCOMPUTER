
#include "modeladm.h" 
#include "mainsimu.h"

#include "keyboard.h"
#include "monitor.h"
#include "harddisk.h"
#include "cpu.h"
#include "memory.h"

void MainSimulator::registerNewAtomics()
{

	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Keyboard>() , "Keyboard" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Monitor>() , "Monitor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Harddisk>() , "Harddisk" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<cpu>() , "cpu" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<memory>() , "memory" ) ;

}
