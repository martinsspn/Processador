#ifndef _PO_
#define _PO_

#include <iostream>
#include "instMem.cpp"
#include "dataMem.cpp"
#include "pc.cpp"
#include "programCounter.cpp"
#include "ula.cpp"
#include "regs.cpp"
#include "multiplex.cpp"
#include "add.cpp"

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
		Add *add;
	public:	
		Po(InstMem *_instMem, DataMem *_dataMem, Pc *_pc, ProgramCounter *_programCounter, Ula *_ula,
		Regs *_regs, Multiplex *_m1, Multiplex *_m2, Multiplex *_m3, Multiplex *_m4,Add *_add){
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
			int x, y, z, k, j, w, h;
			//while(true){
			for(int i=0; i<1; i++){
				pc->getInstruction(instMem->rm(programCounter->get(), pc->instMemRead()));
				x = regs->lr(pc->getOpFont1(), pc->brRead());
				y = m3->getMult(pc->getDest(), regs->lr(pc->getOpFont2(), pc->brRead()), pc->m3Sel());				
				z = ula->op(pc->ulaOp(), x, y);
				h = m4->getMult(pc->getDest(), z, pc->m4Sel(z));
				dataMem->wm(pc->getDataDest(), z ,pc->dataWrite());
				k = dataMem->rm(pc->getDataAddress(), pc->dataRead());
				w = m2->getMult(k, h, pc->m2Sel());
				regs->sr(pc->getDest(), w,pc->brWrite());
				j = add->operar(programCounter->get(), 1);
				programCounter->set(m1->getMult(h, j, pc->m1Sel()), pc->pcWrite());
				
			}
		}	
};

#endif