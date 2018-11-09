#include "headers.h"
#include "methods.h"

int instSize(string str) {

	int i, pos;
	string temp = "";
	string one[] = {"MOV", "XCHG", "ADD", "SUB", "INR", "DCR", "INX", "DCX", "DAD", "CMA", "CMP", "HLT"};
	string two[] = {"MVI", "ADI", "SUI"};
	string three[] = {"JMP", "JC", "JNC", "JZ", "JNZ", "LDA", "STA", "LHLD", "SHLD", "LXI"};
	string four[] = {"SET"};
	pos = str.find(' ');
	if(pos == -1)
		temp = str;
	else
		for(i=0;i<pos;i++)
	 		 temp += str[i];
	for(i=0;i<12;i++) {

		if(temp == one[i])
			return 1;
	}
	for(i=0;i<4;i++) {

		if(temp == two[i])
			return 2;
	}
	for(i=0;i<10;i++) {

		if(temp == three[i])
			return 3;
	}
	if(temp == four[0])
		return 4;
	return -1;
}
