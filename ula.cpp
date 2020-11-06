#ifndef _ULA_
#define _ULA_

#include <iostream>

class ULA {
	private:

	public:
	
	int op(int op, int a, int b) { 
		int s;
		switch(op){
			case 1:	s = a + b;
				break;
			case 2: s = a - b;
				break;
			case 3: s = a * b;
				break;
			case 4: s = a / b;
				break;
			case 5: s = (int)a & (int)b; //op and
				break;
			case 6: s = (int)a | (int)b;//op or
				break;
			case 7: s = !a; //op not
				break;
			case 8: s = a << 2;
				break;
			case 9: if(a - b == 0)
						return 1;
					else
						return 0;
					break;
		}
		return s;
		
	}
};

#endif
