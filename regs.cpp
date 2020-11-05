#ifndef _REGS_
#define _REGS_

#include <iostream>

class Regs{
private:
	unsigned int registradores[32];
	
public:
	unsigned int lr(int adress, bool loadReg) { //Read Register
		if(loadReg)
			return registradores[adress];
	}

	void sr(int adress, unsigned int dado, bool storeReg) { // escreve o valor no registrador selecionado
		if(storeReg)
			registradores[adress] = dado;
	}

};

#endif



