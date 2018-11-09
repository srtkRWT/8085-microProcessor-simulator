#include "headers.h"
#include "methods.h"

string ToHex(bool* Ar)
{

	string T; int i=7,temp,k=2,j=0; char hexa[3];
	while(k--){

		temp =  Ar[i-3] *8 + Ar[i-2] *4 +  Ar[i-1] *2 + Ar[i] ;
		if(temp > 9)
			hexa[j++] = temp + 55;
		else
			hexa[j++] = temp + 48;
		i=i-4;
	}
	hexa[2]='\0';
	T=hexa;
	reverse(T.begin(),T.end());
  	return T;
}