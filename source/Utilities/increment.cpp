#include "headers.h"
#include "methods.h"

string increment(string a2)
{
    if(a2.length()>4 )return "err";
    while(a2.length()<4)
        a2="0"+a2;
        
    
    int i=3,f=0;
    do{
    switch(a2[i])
	{
		case '0':a2[i]='1';f=0;break;
		case '1':a2[i]='2';f=0;break;
		case '2':a2[i]='3';f=0;break;
		case '3':a2[i]='4';f=0;break;
		case '4':a2[i]='5';f=0;break;
		case '5':a2[i]='6';f=0;break;
		case '6':a2[i]='7';f=0;break;
		case '7':a2[i]='8';f=0;break;
		case '8':a2[i]='9';f=0;break;
		case '9':a2[i]='a';f=0;break;
		case 'a':a2[i]='b';f=0;break;
		case 'b':a2[i]='c';f=0;break;
		case 'c':a2[i]='d';f=0;break;
		case 'd':a2[i]='e';f=0;break;
		case 'e':a2[i]='f';f=0;break;
		case 'f':a2[i]='0';f=1;break;
		case 'A':a2[i]='B';f=0;break;
		case 'B':a2[i]='C';f=0;break;
		case 'C':a2[i]='D';f=0;break;
		case 'D':a2[i]='E';f=0;break;
		case 'E':a2[i]='F';f=0;break;
		case 'F':a2[i]='0';f=1;break;
		default : return "err";
	}
	}while(--i>=0 && f);
	return a2;
	
}
