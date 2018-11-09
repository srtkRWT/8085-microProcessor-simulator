#include "headers.h"
#include "methods.h"

void inputFromFile(struct elements *e, string filename) {

	string line;
	ifstream inp(filename.c_str());
	if(!inp){cout<<"\ninvalid input file\n";return;}
	while(!inp.eof()) {

		getline(inp, line);
		transform(line.begin(), line.end(), line.begin(), ::toupper);
		if(line.compare("HLT")==0)
		{
			e->memory[e->pc] = line;
			break;	
		}
		else if(validInst(line)) {

			e->memory[e->pc] = line;
			updatePc(e);
		}
		else
		{
			cout << "\nInvalid instruction! Enter correct instruciton!\n"<<line << endl;
			return;
		}
	}	
}