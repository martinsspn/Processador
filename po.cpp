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

class PO{
	private:
		InstMem instMem;
		DataMem dataMem;
		Pc pc;
		ProgramCounter programCounter;
		Ula ula;
		Regs regs;
		multiplex m1;
		multiplex m2;
		Add add;
	public:	
		PO(InstMem _instMem, DataMem _dataMem, Pc _pc, ProgramCounter _programCounter, Ula _ula,
		Regs _regs, Multiplex _m1, Multiplex _m2, Add _add){
			instMem = _instMem;
			dataMem = _dataMem;
			pc = _pc;
			programCounter = _programCounter;
			ula = _ula;
			regs = _regs;
			m1 = _m1;
			m2 = _m2;
			add = _add;
		}

		void executar(){
			unsigned x, y, z;
			while(true){
				pc.getInstruction(instMem.rm(programCounter.get(), pc.readInstMem()));
				x = regs.lr(pc.getOpFont1(), pc.brRead());
				y = m2.getMult(regs.rr(pc.getOpFont2(), pc.brLead()), pc.getConst(), pc.m2Sel());				
				z = ula.op(pc.ulaOp(), x, y);
				dataMem.wr(pc.getOpFont1(), pc.dataWrite());
				k = dataMem.rr(pc.getOpFont1(), pc.dataRead());
				regs.sr(pc.getOpFont1(), k, pc.storeReg());
				j = add.operar(programCounter.get(), 1);
				programCounter.set(m1.getMult(j, z, pc.m1Sel()), pc.pcWrite());

			}
		}	
}
