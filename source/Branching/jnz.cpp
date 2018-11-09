#include "headers.h"
#include "methods.h"

int jnz(elements *e) {

  map<string,  string> :: iterator it = e->memory.begin();
  string inst = e->memory[e->pc];
  string address = "", instAdd = e->pc;
  int i;
  int p = inst.find(' ');
  for(i = p+1;i<inst.length();i++) {

    address += inst[i];
  }
  if(e->memory.find(address) != (e->memory).end()) {

    if(e->flags[6] == 0)
      e->pc = address;
    else {

      updatePc(e);
    }
    return 1;
  }
  else
    return 0;
}
