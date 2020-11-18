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
		Buffer *buffer1;
		Buffer *buffer2;
		Add *add;
	public:	
		Po(InstMem *_instMem, DataMem *_dataMem, Pc *_pc, ProgramCounter *_programCounter, Ula *_ula,
		Regs *_regs, Multiplex *_m1, Multiplex *_m2, Multiplex *_m3, Multiplex *_m4,Add *_add, Buffer *_buffer1, Buffer *_buffer2){
			instMem = _instMem;
			dataMem = _dataMem;
			pc = _pc;
			programCounter = _programCounter;
			ula = _ula;
			regs = _regs;
			buffer1 = _buffer1;
			buffer2 = _buffer2;
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
				buffer1->buffer[i] = operationType;
				switch(operationType){
					case 1: //sum, sub, div, mult, and, or, beq
						if(pc->opCode == "SUM"){
							buffer2->buffer[i] = ula->op(1, regs->registradores[pc->opFont1], regs->registradores[pc->opFont2], regs->registradores[pc->dataAddress]);
							dataMem->wm(pc->dataAddress, buffer2->buffer[i], true);
							
						}else if(pc->opCode == "SUB"){
							buffer2->buffer[i] = ula->op(2, regs->registradores[pc->opFont1], regs->registradores[pc->opFont2], regs->registradores[pc->dataAddress]);
							dataMem->wm(pc->dataAddress, buffer2->buffer[i], true);

						}else if(pc->opCode == "DIV"){
							buffer2->buffer[i] = ula->op(4, regs->registradores[pc->opFont1], regs->registradores[pc->opFont2], regs->registradores[pc->dataAddress]);
							dataMem->wm(pc->dataAddress, buffer2->buffer[i], true);

						}else if(pc->opCode == "MULT"){
							buffer2->buffer[i] = ula->op(3, regs->registradores[pc->opFont1], regs->registradores[pc->opFont2], regs->registradores[pc->dataAddress]);
							dataMem->wm(pc->dataAddress, buffer2->buffer[i], true);

						}else if(pc->opCode == "AND"){
							buffer2->buffer[i] = ula->op(5, regs->registradores[pc->opFont1], regs->registradores[pc->opFont2], regs->registradores[pc->dataAddress]);
							dataMem->wm(pc->dataAddress, buffer2->buffer[i], true);

						}else if(pc->opCode == "OR"){
							buffer2->buffer[i] = ula->op(6, regs->registradores[pc->opFont1], regs->registradores[pc->opFont2], regs->registradores[pc->dataAddress]);
							dataMem->wm(pc->dataAddress, buffer2->buffer[i], true);

						}else if(pc->opCode == "BEQ"){
							buffer2->buffer[i] = ula->op(9, regs->registradores[pc->opFont1], regs->registradores[pc->opFont2], regs->registradores[pc->dataAddress]);
							dataMem->wm(pc->dataAddress, buffer2->buffer[i], true);

						}
						break;
					case 2: //not, load, store
						if(pc->opCode == "NOT"){
							buffer2->buffer[i] = ula->op(7, regs->registradores[pc->opFont1], 0, regs->registradores[pc->dataAddress]);
							dataMem->wm(pc->dataAddress, buffer2->buffer[i], true);
						}else if(pc->opCode == "LOAD"){
							buffer2->buffer[i] = dataMem->rm(regs->registradores[pc->opFont1], true);
							regs->registradores[pc->dataAddress] = buffer2->buffer[i];
						}else if(pc->opCode == "STORE"){
							buffer2->buffer[i] = regs->registradores[pc->opFont1];
							dataMem->wm(pc->dataAddress, buffer2->buffer[i], true);
						}
						break;
					case 3: //jump
						if(pc->opCode == "JUMP"){
							programCounter->set(pc->opFont1, true);
							i = pc->opFont1;
						}
						break;
					default:
						break;
				}
				programCounter->set(i, true);
				buffer1->buffer[i] = pc->decodificar(instMem->rm(programCounter->get(), true));
				operationType = buffer1->buffer[i];
			}
		}	
};

#endif