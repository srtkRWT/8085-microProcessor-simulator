#include"headers.h"
#include"methods.h"

void display(elements *e)
{
	int i;
	char reg[]={'A','B','C','D','E','H','L'};
	cout << "FLAGS" << endl;
	cout <<  "S Z AC P C" << endl;
	cout << e->flags[7] << " " << e->flags[6] << " " << e->flags[4] << " " << e->flags[2] << " " << e->flags[0] << " " << endl;
	cout << "\n\nREGISTERS\n" << endl;
	for(i=0;i<7;i++)
		cout << reg[i] << " : " << e->registers[i] << endl;
		
	map<string, string>::iterator it = e->memory.begin() ;
	cout << "\n\nMEMORY USED\n" << endl;
	
	while(it != e->memory.end() )
	{
			cout << it->first << " : " << it->second << endl;
			it++;
	} 
	return;
}
