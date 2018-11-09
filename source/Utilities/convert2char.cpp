#include "headers.h"
#include "methods.h"

char convert2char(int digi) {

  	static bool isFirst = true;
  	static std::map<int,char> lookup;
  	if(isFirst) {
		for(int i=0;i<16;++i)
	  		lookup[i] = "0123456789ABCDEF"[i];
	  	isFirst = false;
  	}
  	return lookup[digi];
}