#include "headers.h"
#include "methods.h"

bool* binAdd(bool *Ar1, bool *Ar2, elements *e)
{
	bool *Res = new bool[8];
	bool a,b,c=0;
	for(int i=7;i>=0;i--)
				{
					a=Ar1[i];
					b=Ar2[i];
					Res[i]=a^b^c;
					c=(a&b)|(b&c)|(a&c);
					if(i==4) e->flags[4]=c;
					e->flags[6]= e->flags[6] | Res[i];
					e->flags[2]^=Res[i];
				}
				e->flags[0]=c;
	e->flags[7]=Res[0];
	e->flags[2]=!(e->flags[2]); 
	e->flags[6]=!(e->flags[6]);
	return Res;
}