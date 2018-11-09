#include "headers.h"
#include "methods.h"


int dcx(elements *e)
{
	string inst = e->memory[e->pc];
    string r,x,data;
	bool *Ar1;
	int i; bool a,b,c=1;
    stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
    if(r.length()>1)	return 0;
   
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    transform(r.begin(), r.end(), r.begin(), ::tolower);
    if(!(r[0]=='b'||r[0]=='d'||r[0]=='h'))
	return 0;
	
    int rdd;
    switch(r[0])
	{
		case 'b':rdd=2;break;
		case 'd':rdd=4;break;
		case 'h':rdd=6;break;
		default : return 0;
	}
	Ar1=ToBin(e->registers[rdd]);
	for(i=7;i>=0;i--)
	{
			a=Ar1[i];
			Ar1[i]=(a)^c;
			if(x=="dcx")
			c=((!a)&c);
			else
			c=a&c;
			
	}
	e->registers[rdd]=ToHex(Ar1);
	Ar1=ToBin(e->registers[rdd-1]);
	for(i=7;i>=0;i--)
	{
			a=Ar1[i];
			Ar1[i]=(a)^c;
			if(x=="dcx")
			c=((!a)&c);
			else
			c=a&c;
			
	}
	e->registers[rdd-1]=ToHex(Ar1);
	return 0;	
}