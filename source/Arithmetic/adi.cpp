#include "headers.h"
#include "methods.h"

int adi(elements *e)
{
    string inst = e->memory[e->pc];
    string r,x;
	bool *Ar1,*Ar2,*Res;
	int i; bool a,b,c=0;
	e->flags[5]=e->flags[3]=e->flags[1]=0;
    stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
    transform(x.begin(), x.end(), x.begin(), ::tolower);
	Ar1=ToBin(e->registers[0]);
	Ar2=ToBin(r);
	Res=binAdd(Ar1,Ar2,e);
	e->registers[0]=ToHex(Res);
	return 0;	
}