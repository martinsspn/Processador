#ifndef _ADD_
#define _ADD_

#include <iostream>

class Add{

	public:
		Add();
		~Add();

		unsigned operar(unsigned a, unsigned b){
			return a + b;
		}
}