#include "headers.h"
#include "methods.h"

int mvi(elements *e)
{
    string inst = e->memory[e->pc];
    string a0,a1,a2;
    stringstream ss(inst);
    getline(ss,a0,' ');
    getline(ss,a1,',');
    getline(ss,a2);
    if(a1.length()>1 || a2.length()>2 )return 0;
    if(a2.length()==1)
        a2="0"+a2;
        
    switch(a2[0])
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':break;
		case 'a':a2[0]='A';break;
		case 'b':a2[0]='B';break;
		case 'c':a2[0]='C';break;
		case 'd':a2[0]='D';break;
		case 'e':a2[0]='E';break;
		case 'f':a2[0]='F';break;
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':break;
		default : return 0;
	}
	
	switch(a2[1])
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':break;
		case 'a':a2[1]='A';break;
		case 'b':a2[1]='B';break;
		case 'c':a2[1]='C';break;
		case 'd':a2[1]='D';break;
		case 'e':a2[1]='E';break;
		case 'f':a2[1]='F';break;
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':break;
		default : return 0;
	}
    int rdd;
    switch(a1[0])
	{
		case 'A':
		case 'a':rdd=0;break;
		case 'B':
		case 'b':rdd=1;break;
		case 'C':
		case 'c':rdd=2;break;
		case 'D':
		case 'd':rdd=3;break;
		case 'E':
		case 'e':rdd=4;break;
		case 'H':
		case 'h':rdd=5;break;
		case 'L':
		case 'l':rdd=6;break;
		case 'M':
		case 'm':break;
		default : return 0;
	}
    if(a1[0]=='m' ||a1[0]=='M')
    {
        string memo="";
        memo.append(e->registers[5]);
        memo.append(e->registers[6]);
        e->memory[memo]=a2;
    }
    else
    {
        e->registers[rdd]=a2;
    }    
    return 1;
}  
