#include "headers.h"
#include "methods.h"

void input(struct elements *e) {

	string line;
	fflush(stdin);
	cin.ignore();
	cout << "\nEnter the 8085 code here : " << endl;
	while(1) {

		cout << e->pc << " : ";
		fflush(stdin);
		getline(cin, line);
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
			cout << "\nInvalid instruction! Enter correct instruciton!" << endl;
	}
	cout << "\nEnd of input!" << endl;	
}