#ifndef _DATAMEM_
#define _DATAMEM_

#include <iostream>

class DataMem{
	private:
	unsigned memoria[256];
	public:
	unsigned rm(int end, bool dataRead){ // read memory
		if(dataRead)
			return memoria[end];
	}

	void wm(int end, unsigned dados, bool dataWrite){ //write memory
		if(dataWrite)
			memoria[end] = dados;
	}
};

#endif
