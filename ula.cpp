#ifndef _ULA_
#define _ULA_

#include <iostream>

class ULA {
	private:
	unsigned a, b;
	

	public:
	void readA(double _a) {
		a = _a;
	}
	void readB(double _b) {
		b = _b;
	}
	double writeResult() {
		return(s);
	}
	bool RN(){
		return N;
	} 
	bool RZ(){
		return Z;
	}
	
	void op(int op) { 
		switch(op){
			case 1:	s = a + b;
				break;
			case 2: s = (int)a & (int)b; //op and
				break;
			case 3: s = (int)a | (int)b;//op or
				break;
			case 4: s = !a; //op not
				break;

		}
		if(a < b){ // setando o flag N
			N = true;
		}else{
			N = false;
		}
		if(a==b) { // setando o flag Z
			Z = true;
		}else{
			Z = false;
		}
	}
};

#endif
