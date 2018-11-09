#include "headers.h"
#include "methods.h"

int jmp(elements *e) {

  map<string,  string> :: iterator it;
  string inst = e->memory[e->pc];
  string address = "";
  int i;
  int p = inst.find(' ');
  for(i = p+1;i<inst.length();i++) {

    address += inst[i];
  }
  if(e->memory.find(address) != e->memory.end())
    e->pc = address;
  else
    updatePc(e);
  return 0;
}
