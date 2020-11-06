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
		Multiplex m1;
		Multiplex m2;
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
			int x, y, z, k, j, w;
			//while(true){
			for(int i=0; i<1; i++){
				pc.getInstruction(instMem.rm(programCounter.get(), pc.instMemRead()));
				x = regs.lr(pc.getOpFont1(), pc.brRead());
				y = regs.lr(pc.getOpFont2(), pc.brRead());				
				z = ula.op(pc.ulaOp(), x, y);
				dataMem.wr(z, pc.getDataDest(), pc.dataWrite());
				k = dataMem.rr(pc.getDataAddress(), pc.dataRead());
				w = m2.getMult(k, z, pc.m2Sel());
				regs.sr(w, pc.getDest(), pc.brWrite());
				j = add.operar(programCounter.get(), 1);
				programCounter.set(m1.getMult(z, j, pc.m1Sel()), pc.pcWrite());
			}
		}	
};

#endif