#include "headers.h"
#include "methods.h"

int convert2int(char ch) {

	static bool isFirst = true;
  	static std::map<char,int> lookup;
  	if(isFirst) {
		for(int i=0;i<16;++i)
	  		lookup["0123456789ABCDEF"[i]] = i;
	  	isFirst = false;
  	}
  	return lookup[std::toupper(ch)];
}