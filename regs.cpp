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
	int lr(int address, bool loadReg) { //Read Register
		if(loadReg){
			std::cout << "LOADED DATA: " << registradores[address] << " FROM ADDRESS: " << address << std::endl;
			return registradores[address];
		}
	}

	void sr(int address, int dado, bool storeReg) { // escreve o valor no registrador selecionado
		if(storeReg){
			std::cout << "STORED DATA: " << dado  << " IN ADDRESS: " << address << std::endl;
			registradores[address] = dado;
		}
	}

};

#endif



