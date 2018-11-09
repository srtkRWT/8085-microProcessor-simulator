#include"methods.h"

bool validAddress(string inst) {

  if(inst.length() == 4) {

    if((inst[0] < '2' || inst[0] > '4') || (inst[0] >= 'A' && inst[0] <= 'Z'))
      return false;
    for(int i=0;i<inst.length();i++) {

      if((inst[i] >= '0' && inst[i] <= '9') || (inst[i] >= 'A' && inst[i] <= 'F'))
        continue;
      else
        return false;
    }
  }
  else
    return false;
  return true;
}
