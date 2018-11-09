#include "headers.h"
#include "methods.h"

bool* ToBin(string Hex)
{
  bool *Ar = new bool[8];
  int i=0; string data="";
	
	if(Hex.length()==1)
		data.append("0000");
		
	while(i<Hex.length())
	{
		switch(Hex[i++])
	    {
	        case '0': data.append("0000");break;
	        case '1': data.append("0001");break;
	        case '2': data.append("0010");break;
	        case '3': data.append("0011");break;
	        case '4': data.append("0100");break;
	        case '5': data.append("0101");break;
	        case '6': data.append("0110");break;
	        case '7': data.append("0111");break;
	        case '8': data.append("1000");break;
	        case '9': data.append("1001");break;
	        case 'A':
	        case 'a': data.append("1010");break;
	        case 'B':
	        case 'b': data.append("1011");break;
	        case 'C':
	        case 'c': data.append("1100");break;
	        case 'D':
	        case 'd': data.append("1101");break;
	        case 'E':
	        case 'e': data.append("1110");break;
	        case 'F':
	        case 'f': data.append("1111");break;
	    }
	}
	for(i=0;i<8;i++)
		Ar[i]=(data[i]=='0'?0:1);
  return Ar;
}