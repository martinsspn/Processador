#ifndef _PO_
#define _PO_

#include <iostream>
#include <fstream>
#include "instMem.cpp"
#include "dataMem.cpp"
#include "pc.cpp"
#include "programCounter.cpp"
#include "ula.cpp"
#include "regs.cpp"
#include "multiplex.cpp"
#include "add.cpp"
#include "buffer.cpp"

class Po{
	private:
		InstMem *instMem;
		DataMem *dataMem;
		Pc *pc;
		ProgramCounter *programCounter;
		Ula *ula;
		Regs *regs;
		Multiplex *m1;
		Multiplex *m2;
		Multiplex *m3;
		Multiplex *m4;
		Buffer *buffer;
		Add *add;
	public:	
		Po(InstMem *_instMem, DataMem *_dataMem, Pc *_pc, ProgramCounter *_programCounter, Ula *_ula,
		Regs *_regs, Multiplex *_m1, Multiplex *_m2, Multiplex *_m3, Multiplex *_m4,Add *_add, Buffer *buffer){
			instMem = _instMem;
			dataMem = _dataMem;
			pc = _pc;
			programCounter = _programCounter;
			ula = _ula;
			regs = _regs;
			m1 = _m1;
			m2 = _m2;
			m3 = _m3;
			m4 = _m4;
			add = _add;

		}

		void executar(){
			int operationType;
			operationType = pc->decodificar(instMem->rm(programCounter->get(), true));
			for(int i=0; i<instMem->memoria.size(); i++){
				switch(operationType){
					case 1: //sum, sub, div, mult, and, or, beq
						if(pc->opCode == "SUM"){
							buffer->buffer[i] = ula->op(1, regs->registradores[pc->opFont1], regs->registradores[pc->opFont2], regs->registradores[pc->dataAddress]);
						}else if(pc->opCode == "SUB"){

						}else if(pc->opCode == "DIV"){

						}else if(pc->opCode == "MULT"){

						}else if(pc->opCode == "AND"){

						}else if(pc->opCode == "OR"){

						}else if(pc->opCode == "BEQ"){

						}
						break;
					case 2: //not, load, store
						break;
					case 3: //jump
						break;
					default:
						break;
				}
				programCounter->set(i, true);
				operationType = pc->decodificar(instMem->rm(programCounter->get(), true));
				
			}
		}	
};

#endif