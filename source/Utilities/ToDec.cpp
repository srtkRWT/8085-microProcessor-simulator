#include "headers.h"
#include "methods.h"

int ToDec(string HexVal)
{
	int i=0,Res=0;
  	int l=HexVal.length();
  	while(i<l)
  	{
		if((HexVal[i]>=48)&&(HexVal[i]<=57))
	   		Res=(Res*16)+(HexVal[i]-48);
		else if((HexVal[i]>=65)&&(HexVal[i]<=70))
	   		Res=(Res*16)+(HexVal[i]-55);
		else return -1;
			i++;
  	}
  	return Res;
}