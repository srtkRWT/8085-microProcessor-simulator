#include "headers.h"
#include "methods.h"

int cmp(elements *e)
{
	string inst = e->memory[e->pc];
    string r,x,memo="",data;
	int a,b;
	 stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
    if(r.length()>1)	return 0;
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    if(x!="cmp")
    	return 0;
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
	b=ToDec(data);
	a=ToDec(e->registers[0]);
	if(a>b)
		e->flags[0]=0;
	else if(a<b)
		e->flags[0]=1;
	else if(a==b)
		e->flags[6]=1;
	return 0;
}
