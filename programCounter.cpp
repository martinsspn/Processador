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
				programCounter = _programCounter;
		}
		int get(){
			return programCounter;
		}
};

#endif