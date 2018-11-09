#include "headers.h"
#include "methods.h"

int jz(elements *e) {

  map<string, string> :: iterator it = e->memory.begin();
  string inst = e->memory[e->pc];
  string address = "", instAdd = e->pc;
  int i;
  int p = inst.find(' ');
  for(i = p+1;i<inst.length();i++) {

    address += inst[i];
  }
  cout << address << endl;
  if(e->flags[6] == 1) {

    e->pc = address;
  }
  else {

    updatePc(e);
  }
  return 1;
}
