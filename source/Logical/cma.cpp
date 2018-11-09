#include "headers.h"
#include "methods.h"

int cma(elements *e)
{
	string inst = e->memory[e->pc];
	transform(inst.begin(), inst.end(), inst.begin(), ::tolower);
	bool *Ar;
	if(inst!="cma")
	return 0;
	
	Ar=ToBin(e->registers[0]);
	for(int i=0;i<8;i++)
		Ar[i]=!Ar[i];
	
	e->registers[0]=ToHex(Ar);
	return 1;
}