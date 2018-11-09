#include "headers.h"
#include "methods.h"

int execute(elements *e) {

	string inst, str;
	int p;
	map<string, string>::iterator it;
	it = e->memory.end();
	it--;
	e->pc = e->start;
	while(e->pc != it->first) {

		str = e->memory[e->pc];
		inst = "";
		p = str.find(' ');
		if(p == -1)
			inst = str;
		else
			for(int i=0;i<p;i++)
				inst += str[i];
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
			return 0;
		if(!(inst == "JMP" || inst == "JC" || inst == "JNC" || inst == "JZ" || inst == "JNZ")) {

			updatePc(e);
		}
	} 
	return 0;
}
