#ifndef _INSTMEM_
#define _INSTMEM_

#include <iostream>

class InstMem{
	private:
	std::string memoria[256];
	public:
	std::string rm(int end, bool readInstMem){ // read memory
		if(readInstMem)
			return memoria[end];
	}

	void wm(int end, std::string instrucao, bool writeInstMem){ //write memory
		if(writeInstMem)
			memoria[end] = instrucao;
	}
};

#endif
