#ifndef _INSTMEM_
#define _INSTMEM_

#include <iostream>

class InstMem{
	private:
	int memoria[256];
	public:
	int rm(int end, bool readInstMem){ // read memory
		if(readInstMem)
			return memoria[end];
	}

	void wm(int end, int instrucao, bool writeInstMem){ //write memory
		if(writeInstMem)
			memoria[end] = instrucao;
	}
};

#endif
