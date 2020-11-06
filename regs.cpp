#ifndef _REGS_
#define _REGS_

#include <iostream>

class Regs{
private:
	//int registradores[32];
	
public:
	int registradores[32];
	Regs(){
		registradores[0] = 0; //valor padrão do registrador 0
		registradores[1] = 10;
		registradores[2] = 5;
	}
	int lr(int adress, bool loadReg) { //Read Register
		if(loadReg)
			return registradores[adress];
	}

	void sr(int adress, int dado, bool storeReg) { // escreve o valor no registrador selecionado
		if(storeReg)
			registradores[adress] = dado;
	}

};

#endif



