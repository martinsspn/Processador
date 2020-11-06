#include <iostream>
#include "pc.cpp"
#include "po.cpp"
#include "regs.cpp"
#include "instMem.cpp"
#include "dataMem.cpp"
#include "multiplex.cpp"
#include "programCounter.cpp"
#include "ula.cpp"
#include "add.cpp"

using namespace std;
int main(){
	InstMem instMem = new InstMem();
	DataMem dataMem = new DataMem();
	Pc pc = new Pc();
	ProgramCounter programCounter = new ProgramCounter();
	Ula ula = new Ula();
	Regs regs = new Regs();
	Multiplex m1 = new Multiplex();
	Multiplex m2 = new Multiplex();
	Add add = new Add();
	Po po = new Po(instMem, dataMem, pc, programCounter, ula, regs, m1, m2, add);
	cout << regs.registradores[1];
	po.executar();
	cout << regs.registradores[1];
}