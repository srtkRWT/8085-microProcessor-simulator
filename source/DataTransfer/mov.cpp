#include "headers.h"
#include "methods.h"

int mov(elements *e)
{
    string inst = e->memory[e->pc];
    string a0,a1,a2;
    stringstream ss(inst);
    getline(ss,a0,' ');
    getline(ss,a1,',');
    getline(ss,a2);
    if(a1.length()>1 || a2.length()>1 ||(a1[0]=='M'&&a2[0]=='M'))return 0;
    int rdd,rss;
    switch(a1[0])
	{
		case 'A':rdd=0;break;
		case 'B':rdd=1;break;
		case 'C':rdd=2;break;
		case 'D':rdd=3;break;
		case 'E':rdd=4;break;
		case 'H':rdd=5;break;
		case 'L':rdd=6;break;
		case 'M':break;
		default : return 0;
	}
	
	switch(a2[0])
	{
		case 'A':rss=0;break;
		case 'B':rss=1;break;
		case 'C':rss=2;break;
		case 'D':rss=3;break;
		case 'E':rss=4;break;
		case 'H':rss=5;break;
		case 'L':rss=6;break;
		case 'M':break;
		default : return 0;
	}
    
    if(a1[0]=='M' || a2[0]=='M')
    {
        string memo="";
        memo.append(e->registers[5]);
        memo.append(e->registers[6]);
        
        if(a1[0]=='M')
        {
            e->memory[memo]=e->registers[rss];
        }
        else
        {
            e->registers[rdd]=e->memory[memo];
        }
        
    }
    else
        e->registers[rdd]=e->registers[rss];
    return 0;
}   
