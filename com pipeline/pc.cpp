#ifndef _PC_
#define _PC_

#include <iostream>
#include <sstream>
#include <vector>
#include "programCounter.cpp"

using namespace std;

class Pc{
public:
		ProgramCounter *programCounter;
		string palavra_de_instrucao;
		string opCode;
		int opFont1;
		int opFont2;
		int dest;
		int dataDest;
		int dataAddress;
		int ulaOpControl;
		bool loadRegControl;
		bool storeRegControl;
		bool pcWriteControl;
		bool seletorControl;
		bool readInstMemControl;
		bool writeInstMemControl;
		bool dataReadControl;
		bool dataWriteControl;
	
		Pc(ProgramCounter *_programCounter){
			programCounter = _programCounter;
			palavra_de_instrucao = "";
			opCode = "";
			opFont1 = 0;
			opFont2 = 0;
			dest = 0;
			dataDest = 0;
			dataAddress = 0;
			ulaOpControl = 0;
			loadRegControl = false;
			storeRegControl = false;
			pcWriteControl = false;
			seletorControl = false;
			readInstMemControl = false;
			writeInstMemControl = false;
			dataReadControl = false;
			dataWriteControl = false;
		}

		int decodificar(string command){
			stringstream operations(command);
			string aux1;
			vector<string> aux2; //ADD 3 6 9
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
					return 1;
				}catch(exception& e){
					cout << "There's something wrong with the instruction" << endl;
				}	
			}else if(aux2.size() == 3){
				try{
					this->opCode = aux2[0];
					this->opFont1 = stoi(aux2[1]);
					this->dest = stoi(aux2[2]);
					return 2;
				}catch(exception& e){
					cout << "There's something wrong with the instruction" << endl;
				}
			}else if(aux2.size() == 2){
				try{
					this->opCode = aux2[0];
					this->dest = stoi(aux2[1]);
					return 3;
				}catch(exception& e){
					cout << "There's something wrong with the instruction" << endl;
				}
			}else{
				cout << "Invalid Operation" << endl;
				return 0;
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
			if (readInstMemControl){
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
			if (opCode == "ADD" || opCode == "SUB" || opCode == "MULT" || opCode == "DIV" || opCode == "AND" || opCode == "OR" || opCode == "NOT" || opCode == "SHIFT" || opCode == "LOAD" || opCode == "BEQ"){
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
