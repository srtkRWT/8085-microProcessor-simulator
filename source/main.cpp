#include "headers.h"
#include "methods.h"
	  
int main(int argc, char* argv[]) {

	struct elements e;
	setValues(&e);
	string  tmp;
	switch(argc) {

		case 1:
	  		cout << "\nNo input file selected!\nEnter code from command line!" << endl;
			getStart(&e);
			fflush(stdin);
			input(&e);
			fflush(stdin);
			execute(&e);
			display(&e);
	  	break;
	  	case 2:
			tmp = argv[1];
			if(tmp.compare("--debug")==0 ) {

				cout << "Debugging mode selected" << endl;
				getStart(&e);
				fflush(stdin);
				input(&e);	
				execute(&e);
				display(&e);
				fflush(stdin);
				debug(&e);
				display(&e);
			}
			else {

		  		cout << "\nSource file provided" << endl;
		  		cout<<argv[1]<<endl;
				getStart(&e);
				fflush(stdin);
				inputFromFile(&e,argv[1]);
				fflush(stdin);
				execute(&e);
				display(&e);
			}
	  	break;
	  	case 3:
			tmp = argv[1];
			if(!(tmp.compare("--debug")==0 || tmp.compare("--debug")==0) ) {

				cout<<"\ninvalid arguments\n\n";
				break;
			}
			cout << "Debugging mode with source file selected" << endl;
			getStart(&e);		
			fflush(stdin);
			inputFromFile(&e,argv[2]);
			execute(&e);
			display(&e);
			fflush(stdin);
			debug(&e);
			display(&e);
	  	break;
	  	default :
			cout << "Invalid mode selected" << endl;
	}
	return 0;
}
