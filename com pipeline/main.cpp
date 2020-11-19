#include <iostream>
#include "buffer.cpp"
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
	InstMem *instMem = new InstMem();
	DataMem *dataMem = new DataMem();
	ProgramCounter *programCounter = new ProgramCounter();
	Ula *ula = new Ula();
	Regs *regs = new Regs();
	Multiplex *m1 = new Multiplex();
	Multiplex *m2 = new Multiplex();
	Multiplex *m3 = new Multiplex();
	Multiplex *m4 = new Multiplex();
	Buffer *buffer1 = new Buffer();
	Buffer *buffer2 = new Buffer();
	Add *add = new Add();
	Pc *pc =  new Pc(programCounter);
	Po *po = new Po(instMem, dataMem, pc, programCounter, ula, regs, m1, m2, m3, m4, add, buffer1, buffer2);
	cout << regs->registradores[1] << endl;
	po->executar();
	cout << regs->registradores[1] << endl;
	
}