#ifndef _PROGRAMCOUNTER_
#define _PROGRAMCOUNTER_

#include <iostream>

class ProgramCounter{
	private:
		int programCounter;
	public:
		ProgramCounter(){
			programCounter = 0;
		}
		
		void set(int _programCounter, bool pcWrite){
			if(pcWrite)
				std::cout << "Novo valor do programCounter: " << _programCounter << std::endl;
				programCounter = _programCounter;
		}
		int get(){
			return programCounter;
		}
};

#endif