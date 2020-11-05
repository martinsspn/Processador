#ifndef _PC_
#define _PC_

#include <iostream>
#include <vector>

using namespace std;

class PC{
	private:
		string palavra_de_instrucao;
		string opCode;


	public:
		void decodificar(){
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

		void getInstruction(string _instrucao){
			palavra_de_instrucao = _instrucao;
		}

		bool pcWrite(){		
			if (true)
				return true;
			else
				return false;
		}

		bool instMemWrite(){
			if (opCode = "SW")
				return true;
			else
				return false;	
		}

		bool instMemRead(){
			if (opCode == "LW")
				return true;
			else
				return false;
		}

		bool brWrite(){
			if (opCode == ?)
				return true;
			else
				return false;
		}

		bool m1Sel(){
			if (opCode == ?)
				return true;
			else
				return false;
		}

		bool m2Sel(){
			if (opCode == ?)
				return true;
			else
				return false;
		}

		unsigned opUla(){
			if (opCode == ?)
				return something;
			else
				return something;
		}

		bool dataMemRead(){
			if (opCode == ?)
				return true;
			else
				return false;
		}

		bool dataMemWrite(){
			if (opCode == ?)
				return true;
			else
				return false;
		}
#endif
