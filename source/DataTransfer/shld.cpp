#include "headers.h"
#include "methods.h"

int shld(elements *e)
{
    string inst = e->memory[e->pc];
    string a0,a1,a2;
    stringstream ss(inst);
    getline(ss,a0,' ');
    //getline(ss,a1,',');
    getline(ss,a2);
    
    if(a2.length()>4 )return 0;
    while(a2.length()<4)
        a2="0"+a2;
        
    
    int i=0;
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
	    map<string , string>::iterator it = e->memory.find(a2);
    it->second =e->registers[6];
    it++;
    it->second=e->registers[5];
    return 1;
}
   
