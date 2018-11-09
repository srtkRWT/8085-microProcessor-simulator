#include "headers.h"
#include "methods.h"

int lxi(elements *e)
{
    string inst = e->memory[e->pc];
    string a0,a1,a2;
    stringstream ss(inst);
    getline(ss,a0,' ');
    getline(ss,a1,',');
    getline(ss,a2);
    
    if(a2.length()>4 )return 0;
    while(a2.length()<4)
        a2="0"+a2;
        
    
    int i=0,rdd;
    do{
    switch(a2[i])
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
		case 'a':a2[i]='A';break;
		case 'b':a2[i]='B';break;
		case 'c':a2[i]='C';break;
		case 'd':a2[i]='D';break;
		case 'e':a2[i]='E';break;
		case 'f':a2[i]='F';break;
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':break;
		default : return 0;
	}
	}while(++i<4);
	    
    switch(a1[0])
	{
		case 'B':rdd=1;break;
		case 'D':rdd=3;break;
		case 'H':rdd=5;break;
		default : return 0;
	}
	e->registers[rdd]=a2.substr(0,2);
	e->registers[rdd+1]=a2.substr(2,2);
    return 1;
}

