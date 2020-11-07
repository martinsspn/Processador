#ifndef _PC_
#define _PC_

#include <iostream>
#include <vector>
#include "programCounter.cpp"

using namespace std;

class Pc{
	private:
		ProgramCounter *programCounter;
		string palavra_de_instrucao;
		string opCode;
		int opFont1;
		int opFont2;
		int dest;
		int dataDest;
		int dataAddress;

	public:
		Pc(ProgramCounter * _programCounter){
			programCounter = _programCounter;
			palavra_de_instrucao = "";
			opCode = "JUMP";
			opFont1 = 1;
			opFont2 = 2;
			dest = 12;
			dataDest = 15;
			dataAddress = 15;
		}

		/*void decodificar(){
			vector<string> x;
			string y ="";
			for(auto n = palavra_de_instrucao.begin(), n < palavra_de_instrucao.end(), ++n){
				if(palavra_de_instrucao[n] != " " or palavra_de_instrucao[n] != ";")
					y += palavra_de_instrucao[n];
				else
					x.push_back(y);
			}
			opCode = x[0];
		
		}
		*/

		void getInstruction(string _instrucao){
			palavra_de_instrucao = _instrucao;
		}

		bool pcWrite(){		
			if (true){
				cout << "pcWrite" << endl;
				return true;
			}else{
				return false;
			}
		}


		bool instMemRead(){
			if (true){
				cout << "instMemRead" << endl;
				return true;
			}else{
				return false;
			}
		}

		bool dataRead(){
			if(opCode == "STORE"){
				cout << "dataRead" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		bool dataWrite(){
			if(opCode == "LOAD"){
				cout << "dataWrite" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		bool brRead(){
			if (opCode == "ADD" || opCode == "SUB" || opCode == "MULT" || opCode == "DIV" || opCode == "AND" || opCode == "OR" || opCode == "NOT" || opCode == "SHIFT" || opCode == "LOAD"){
				cout << "brRead" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		bool brWrite(){
			if (opCode == "ADD" || opCode == "SUB" || opCode == "MULT" || opCode == "DIV" || opCode == "AND" || opCode == "OR" || opCode == "NOT" || opCode == "SHIFT" || opCode == "STORE"){
				cout << "brWrite" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		bool m1Sel(){
			if (opCode == "JUMP" || opCode == "BEQ"){
				cout << "m1Sel" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		bool m2Sel(){
			if (opCode == "STORE"){
				cout << "m2Sel" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		int ulaOp(){
			cout << "opUla: ";
			if(opCode == "ADD" || opCode == "LOAD" || opCode == "JUMP"){cout << "ADD/LOAD/JUMP" << endl; return 1; }
			else if(opCode == "SUB"){cout << "SUB" << endl; return 2; }
			else if(opCode == "MULT"){cout << "MULT" << endl; return 3; }
 			else if(opCode == "DIV"){cout << "DIV" << endl; return 4; }
			else if(opCode == "AND"){cout << "AND" << endl; return 5; }
			else if(opCode == "OR"){cout << "OR" << endl; return 6; }
			else if(opCode == "NOT"){cout << "NOT" << endl; return 7; } 
			else if(opCode == "SHIFT"){cout << "SHIFT" << endl; return 8; }
			else if(opCode == "BEQ"){cout << "BEQ" << endl; return 9; }
		}

		int getOpFont1(){
			cout << "getOpFont1" << endl;
			if(opCode == "JUMP")
				return programCounter->get();
			else
				return opFont1;
		}


		int getOpFont2(){
			cout << "getOpFont2" << endl;
			if(opCode == "LOAD")
				return 0;
			else if(opCode == "JUMP")
				return dest;
			else
				return opFont2;
		}

		int getDataDest(){
			cout << "getDataDest" << endl;
			return dataDest;
		}

		int getDataAddress(){
			cout << "getDataAddress" << endl;
			return dataAddress;
		}

		int getDest(){
			cout << "getDest" << endl;
			return dest;
		}
};
#endif
