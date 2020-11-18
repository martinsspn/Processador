#ifndef _INSTMEM_
#define _INSTMEM_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class InstMem{
private:
	vector<string> memoria;
public:
	InstMem(){
		ifstream file;
		file.open("code.txt");
		string op;
		getline(file, op);
		memoria.push_back(op);
	}

	string rm(int end, bool readInstMem){ // read memory
		if(readInstMem)
			return memoria[end];
		else
			return "";
	}

	void wm(int end, string instrucao, bool writeInstMem){ //write memory
		if(writeInstMem)
			memoria[end] = instrucao;
	}
};

#endif