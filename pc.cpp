#ifndef _PC_
#define _PC_

#include <iostream>
#include <vector>

using namespace std;

class PC{
	private:
		string palavra_de_instrucao;
		string opCode;
		int opFont1;
		int opFont2;
		int dest;
		int dataDest;
		int dataAddress;

	public:
		PC(){
			palavra_de_instrucao = "";
			opCode = "ADD";
			opFont1 = 1;
			opFont2 = 2;
			dest = 1;
			dataDest = 0;
			dataAddress = 0;
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
			if (true)
				return true;
			else
				return false;
		}


		bool instMemRead(){
			if (true)
				return true;
			else
				return false;
		}

		bool dataRead(){
			if(opCode == "STORE")
				return true;
			else
				return false;
		}

		bool dataWrite(){
			if(opCode == "LOAD")
				return true;
			else
				return false;
		}

		bool brRead(){
			if (opCode == "ADD" || opCode == "SUB" || opCode == "MULT" || opCode == "DIV" || opCode == "AND" || opCode == "OR" || opCode == "NOT" || opCode == "SHIFT" || opCode == "LOAD")
				return true;
			else
				return false;
		}

		bool brWrite(){
			if (opCode == "ADD" || opCode == "SUB" || opCode == "MULT" || opCode == "DIV" || opCode == "AND" || opCode == "OR" || opCode == "NOT" || opCode == "SHIFT" || opCode == "STORE")
				return true;
			else
				return false;
		}

		bool m1Sel(){
			if (opCode == "JUMP" || opCode == "BEQ")
				return true;
			else
				return false;
		}

		bool m2Sel(){
			if (opCode == "STORE")
				return true;
			else
				return false;
		}

		int opUla(){
			switch(opCode){
				case "ADD": return 1; break;
				case "SUB": return 2; break;
				case "MULT": return 3; break;
				case "DIV": return 4; break;
				case "AND": return 5; break;
				case "OR": return 6; break;
				case "NOT": return 7; break;
				case "SHIFT": return 8; break;
				case "LOAD": return 1; break;
				case "BEQ": return 9; break;
				case "JUMP": return 1; break;
			}
		}

		int getOpFont1(){
			return opFont1;
		}

		int getOpFont2(){
			return opFont2;
		}

		int getDataDest(){
			return dataDest;
		}

		int getDataAddress(){
			return dataAddress;
		}
};
#endif
