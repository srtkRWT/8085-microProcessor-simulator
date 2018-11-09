#include "headers.h"
#include <sstream>
#include "methods.h"
using namespace std;

int sett(elements *e)
{
    string inst = e->memory[e->pc];
    string a0,a1,a2;
    
    stringstream ss(inst);
    getline(ss,a0,' ');
    getline(ss,a1,' ');
    getline(ss,a2);
    
    if(a1.length()>4 || a2.length()>2 )return 0;
    
    
    if(a1.length()>4 )return 0;
    while(a1.length()<4)
        a1="0"+a1;
        
    
    int i=0;
    do{
    switch(a1[i])
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
		case 'a':a1[i]='A';break;
		case 'b':a1[i]='B';break;
		case 'c':a1[i]='C';break;
		case 'd':a1[i]='D';break;
		case 'e':a1[i]='E';break;
		case 'f':a1[i]='F';break;
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':break;
		default : return 0;
	}
	}while(++i<4);
	    
    
    if(a2.length()>2 )return 0;
    while(a2.length()<2)
        a2="0"+a2;
        
    
    i=0;
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
	}while(++i<2);
	
	e->memory[a1]=a2;
    return 1;
}

