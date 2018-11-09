#include "headers.h"
#include "methods.h"

void setValues(struct elements *e) {

	int i;
	for(i=0;i<8;i++)
		(e->flags)[i] = 0;
	for(i=0;i<7;i++)
		(e->registers)[i] = "00";
}