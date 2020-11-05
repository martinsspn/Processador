#ifndef _MULTIPLEX_
#define _MULTIPLEX_

#include <iostream>

class multiplex
{
public:
	multiplex();
	~multiplex();
	
	unsigned getMult(unsigned A, unsigned B, bool seletor){
		if(seletor){
			return A;
		}else{
			return B;
		}
	}
};