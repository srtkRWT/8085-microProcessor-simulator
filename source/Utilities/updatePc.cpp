#include "headers.h"
#include "methods.h"

int updatePc(elements *e) {

	int size;
	string str;
	size = instSize(e->memory[e->pc]);
	if(size == 1)
		str = "0001";
	else if(size == 2)
		str = "0002";
	else if(size == 3)
		str = "0003";
	else if(size == 4)
		str = "0004";
	e->pc = addPc(e->pc, str);
	return 0;
}
