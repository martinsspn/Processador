#ifndef _PC_
#define _PC_

#include <iostream>
#include <sstream>
#include <fstream>
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
			opCode = "BEQ";
			opFont1 = 1;
			opFont2 = 1;
			dest = 10;
			dataDest = 15;
			dataAddress = 15;
		}

		void decodificar(){
			stringstream operations(palavra_de_instrucao);
			string aux1;
			vector<string> aux2;
			while(!operations.eof()){
				operations >> aux1;
				aux2.push_back(aux1);
			}
			if(aux2.size() == 4){
				try{
					this->opCode = aux2[0];
					this->opFont1 = stoi(aux2[1]);
					this->opFont2 = stoi(aux2[2]);
					this->dest = stoi(aux2[3]);
				}catch(exception& e){
					cout << "There's something wrong with the instruction";
				}	
			}else if(aux2.size() == 3){
				try{
					this->opCode = aux2[0];
					this->opFont1 = stoi(aux2[1]);
					this->dest = stoi(aux2[2]);
					this->dataAddress = stoi(aux2[1]);
					this->dataDest = stoi(aux2[2]);

				}catch(exception& e){
					cout << "There's something wrong with the instruction";
				}
			}else if(aux2.size() == 2){
				try{
					this->opCode = aux2[0];
					this->dest = stoi(aux2[1]);
				}catch(exception& e){
					cout << "There's something wrong with the instruction" << endl;
				}
			}else if(aux2.size() == 1){
				try{
					this->opCode = aux2[0];
				}catch(exception& e){
					cout << "There's something wrong with the instruction" << endl;	
				}
			}else{
				cout << "Invalid Operation" << endl;
			}
		}

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
			if(opCode == "LOAD"){
				cout << "dataRead" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		bool dataWrite(){
			if(opCode == "STORE"){
				cout << "dataWrite" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		bool brRead(){
			if (opCode == "ADD" || opCode == "SUB" || opCode == "MULT" || opCode == "DIV" || opCode == "AND" || opCode == "OR" || opCode == "NOT" || opCode == "SHIFT" || opCode == "STORE" || opCode == "BEQ"){
				cout << "brRead" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		bool brWrite(){
			if (opCode == "ADD" || opCode == "SUB" || opCode == "MULT" || opCode == "DIV" || opCode == "AND" || opCode == "OR" || opCode == "NOT" || opCode == "SHIFT" || opCode == "LOAD"){
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
			if (opCode == "LOAD"){
				cout << "m2Sel" << endl;
				return true;
			}
			else{
				return false;
			}
		}

		bool m3Sel(){
			cout << "m3Sel" << endl;
			if (opCode == "JUMP"){
				return true;
			}else{
				return false;
			}
		}

		bool m4Sel(int z){
			if(opCode == "BEQ" && z == 1)
				return true;
			else
				return false;
		}

		int ulaOp(){
			cout << "opUla: ";
			if(opCode == "ADD" || opCode == "STORE" || opCode == "JUMP"){cout << "ADD/STORE/JUMP" << endl; return 1; }
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
			if(opCode == "STORE")
				return 0;
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

		string getOpCode(){
			return opCode;
		}
};
#endif