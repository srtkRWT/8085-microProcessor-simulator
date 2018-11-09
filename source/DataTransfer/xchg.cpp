#include "headers.h"
#include <sstream>
#include "methods.h"

using namespace std;

int xchg(elements *e)
{
    string tmp;
    tmp=e->registers[3];
    e->registers[3]=e->registers[5];
    e->registers[5]=tmp;
    
    tmp=e->registers[4];
    e->registers[4]=e->registers[6];
    e->registers[6]=tmp;
    return 0;
}
   
