#ifndef _INSTMEM_
#define _INSTMEM_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class InstMem{
public:
	vector<string> memoria;

	InstMem(){
		ifstream file;
		file.open("code.txt");
		string op;
		while(!file.eof()){
			getline(file, op);
			memoria.push_back(op);
		}
	}

	string rm(int end, bool readInstMem){ // read memory
		if(readInstMem)
			return memoria[end];
	}

	void wm(int end, string instrucao, bool writeInstMem){ //write memory
		if(writeInstMem)
			memoria[end] = instrucao;
	}
};

#endif
