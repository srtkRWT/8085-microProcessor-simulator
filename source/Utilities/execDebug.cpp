#include "headers.h"
#include "methods.h"

void execDebug(elements *e)
{
	string inst="";
	int p;
	inst = e->memory[e->pc ];
	string cmd;
	stringstream ss(inst);
	ss >> inst;
	if(inst == "MOV")
		mov(e);
	else if(inst == "XCHG")
		xchg(e);
	else if(inst == "ADD")
		add(e);
	else if(inst == "SUB")
		sub(e);
	else if(inst == "INR")
		inr(e);
	else if(inst == "DCR")
		dcr(e);
	else if(inst == "INX")
		inx(e);
	else if(inst == "DCX")
		dcx(e);
	else if(inst == "DAD")
		dad(e);
	else if(inst == "CMA")
		cma(e);
	else if(inst == "CMP")
		cmp(e);
	else if(inst == "MVI")
		mvi(e);
	else if(inst == "LXI")
		lxi(e);
	else if(inst == "ADI")
		adi(e);
	else if(inst == "SUI")
		sui(e);
	else if(inst == "JMP")
		jmp(e);
	else if(inst == "JC")
		jc(e);
	else if(inst == "JNC")
		jnc(e);
	else if(inst == "JZ")
		jz(e);
	else if(inst == "JNZ")
		jnz(e);
	else if(inst == "LDA")
		lda(e);
	else if(inst == "STA")
		sta(e);
	else if(inst == "LHLD")
		lhld(e);
	else if(inst == "SHLD")
		shld(e);
	else if(inst == "SET")
		sett(e);
	else if(inst == "HLT")
		return;	
	if(!(inst == "JMP" || inst == "JC" || inst == "JNC" || inst == "JZ" || inst == "JNZ"))
		updatePc(e);
}