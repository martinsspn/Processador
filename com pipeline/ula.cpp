#ifndef _ULA_
#define _ULA_

#include <iostream>
using namespace std;
class Ula{
public:
	int op(int op, int a, int b, int adress) { 
		int s;
		switch(op){
			case 1:	
				s = a + b;
				std::cout << "ADD FINISHED WITH A: " << a << " B: " << b << endl;
				break;
			case 2: 
				s = a - b; 
				std::cout << "SUB FINISHED" << endl;
				break;
			case 3: 
				s = a * b; std::cout << "MULT FINISHED" << endl;
				break;
			case 4: 
				s = a / b; 
				std::cout << "DIV FINISHED" << endl;
				break;
			case 5: 
				s = (int)a & (int)b; 
				std::cout << "AND FINISHED" << endl; //op and 
				break;
			case 6: 
				s = (int)a | (int)b; 
				std::cout << "OR FINISHED" << endl;//op or
				break;
			case 7: 
				s = !a; 
				std::cout << "NOT FINISHED" << endl; //op not
				break;
			case 8: 
				s = a << 2; 
				std::cout << "SHIFT FINISHED" << endl;
				break;
			case 9: 
				if(a - b == 0)
					s = adress;
				std::cout << "BEQ FINISHED" << endl;
				break;
		}
		
		return s;	
	}
};

#endif
