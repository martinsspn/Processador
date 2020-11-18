#ifndef _DATAMEM_
#define _DATAMEM_

#include <iostream>

class DataMem{
	private:
	int memoria[256];
	public:
	DataMem(){
		memoria[15] = 25;
	}
	int rm(int end, bool dataRead){ // read memory
		if(dataRead)
			std::cout << "READ DATA: " << memoria[end] << " FROM DATA MEM. ADDRESS: "<< end << std::endl;
			return memoria[end];
	}

	void wm(int end, int dados, bool dataWrite){ //write memory
		if(dataWrite)
			std::cout << "WRITE DATA: "<< dados << " IN DATA MEM. ADDRESS: " << end << std::endl;
			memoria[end] = dados;
	}
};

#endif