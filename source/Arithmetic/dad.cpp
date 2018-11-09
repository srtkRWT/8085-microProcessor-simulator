#include "headers.h"
#include "methods.h"

int dad(elements *e)
{
	string inst = e->memory[e->pc];
    string r,x,data;
	bool *Ar1,*Ar2,*Res;
	int i; bool a,b,c=0;
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
	Ar2=ToBin(e->registers[rdd]);
	Ar1=ToBin(e->registers[6]);
	for(i=7;i>=0;i--)
	{
		a=Ar1[i];
		b=Ar2[i];
		Res[i]=a^b^c;
		c=(a&b)|(b&c)|(a&c);
	}
	e->registers[6]=ToHex(Res);
	Ar2=ToBin(e->registers[rdd-1]);
	Ar1=ToBin(e->registers[5]);
	for(i=7;i>=0;i--)
	{
		a=Ar1[i];
		b=Ar2[i];
		Res[i]=a^b^c;
		c=(a&b)|(b&c)|(a&c);
	}
	e->flags[0]=1;
	e->registers[5]=ToHex(Res);
	return 1;		
}