#include "headers.h"
#include "methods.h"

int sub(elements *e)
{
    string inst = e->memory[e->pc];
    string r,x,memo="",data;
	bool *Ar1,*Ar2,*Res,*Re;
	int i; bool a,b,c=0;
	e->flags[5]=e->flags[3]=e->flags[1]=0;
    stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
    if(r.length()>1)	return 0;
   
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    transform(r.begin(), r.end(), r.begin(), ::tolower);
    if(!(r[0]=='a'||r[0]=='b'||r[0]=='c'||r[0]=='d'||r[0]=='e'||r[0]=='h'||r[0]=='l'||r[0]=='m'))
	return 0;
	
    int rdd;
    switch(r[0])
	{
		
		case 'a':rdd=0;break;
		case 'b':rdd=1;break;
		case 'c':rdd=2;break;
		case 'd':rdd=3;break;
		case 'e':rdd=4;break;
		case 'h':rdd=5;break;
		case 'l':rdd=6;break;
		case 'm':break;
		default : return 0;
	}
	if(r[0]=='m' || r[0]=='M')
	{
        memo.append(e->registers[5]);
        memo.append(e->registers[6]);
        data=e->memory[memo];
	}
	else
		data=e->registers[rdd];
	Ar2=ToBin(data);
	Ar1=ToBin(e->registers[0]);
	e->flags[6]=e->flags[2]=e->flags[0]=0;	
	Res=binSub(Ar1,Ar2,e);
	e->registers[0]=ToHex(Res);
	return 0;	
}