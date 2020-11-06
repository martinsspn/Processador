#ifndef _DATAMEM_
#define _DATAMEM_

#include <iostream>

class DataMem{
	private:
	int memoria[256];
	public:
	int rm(int end, bool dataRead){ // read memory
		if(dataRead)
			return memoria[end];
	}

	void wm(int end, int dados, bool dataWrite){ //write memory
		if(dataWrite)
			memoria[end] = dados;
	}
};

#endif
