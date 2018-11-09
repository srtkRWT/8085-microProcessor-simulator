#include "headers.h"
#include "methods.h"

void getStart(struct elements *e) {

	string str;
	while(1) {

		cout << "Enter the starting address : ";
	  	cin >> str;
	  	if(validAddress(str)) {

			e->pc = str;
			e->start = str;
			break;
	  	}
	  	else
			cout << "Invalid Address! Try again " << endl;
	}
}