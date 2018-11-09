#include "headers.h"
#include "methods.h"

string addPc(string hex1,string hex2) {
	int carry = 0;
  	string sum = "";
  	for(int i=0 ; i<hex1.length() ; ++i)
		sum += " ";
  	for(int i=hex1.length()-1 ; i>=0 ; --i) {
		int tmp = convert2int(hex1[i])+convert2int(hex2[i])+carry;
		if(tmp < 16)
			carry = 0;
		else {
	  		carry = 1;
	  		tmp -= 16;
		}
		sum[i] = convert2char(tmp);
  	}
  	return sum;
}
