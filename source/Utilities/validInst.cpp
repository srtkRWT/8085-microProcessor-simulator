#include "headers.h"
#include "methods.h"
// #include<bits/stdc++.h>
// using namespace std;

bool val16(string str) {

  int c = 0, i;
  if(str.length() == 4) {

    for(i=0;i<4;i++) {

      if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
        c++;
    }
    if(c == 4)
      return true;
  }
  return false;
}

bool val8(string str) {

  int c = 0, i;
  if(str.length() == 2) {

    for(i=0;i<2;i++) {

      if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
        c++;
    }
    if(c == 2)
      return true;
  }
  return false;
}

bool fourByte(vector<string> v) {

  if(v.size() != 3)
    return false;
  else if(val16(v[1]) && val8(v[2]))
    return true;
  else
    return false;
}

bool threeByte(vector<string>  v) {

  if(v.size() == 1)
    return false;
  else if(v.size() == 2) {

    if(val16(v[1]) && v[0] != "LXI")
      return true;
  }
  else if(v.size() == 3) {

    if(val16(v[2]))
      return true;
  }
  return false;
}

bool twoByte(vector<string> v) {

  int i;
  string lookup[] = {"A", "B", "C", "D", "E", "H", "L", "M"};
  if(v.size() == 1)
    return false;
  else if(v.size() == 2) {

    if(v[0] == "ADI" || v[0] == "SUI") {

      if(val8(v[1]))
        return true;
    }
  }
  else if(v.size() == 3) {

    for(i=0;i<7;i++) {

      if(v[1] == lookup[i]) {

        if(v[0] == "MVI"){

          if(val8(v[2]))
            return true;
        }
      }
    }
  }
  return false;
}

bool oneByte(vector<string> v) {

  int i, j;
  string lookup[] = {"A", "B", "C", "D", "E", "H", "L", "M"};
  if(v.size() == 1) {

    if(v[0] == "XCHG" || v[0] == "CMA" || v[0] == "HLT")
      return true;
    return false;
  }
  else if(v.size() == 2) {

    if(v[0] == "INR" || v[0] == "DCR" || v[0] == "INX" || v[0] == "DCX" || v[0] == "DAD" || v[0] == "CMP" || v[0] == "ADD" || v[0] == "SUB") {

      for(i=0;i<8;i++) {

        if(v[1] == lookup[i])
          return true;
      }
    }
    return false;
  }
  else if(v.size() == 3) {

    if(v[0] == "MOV") {

      for(i=0;i<8;i++) {

        if(v[1] == lookup[i]) {

          for(j=0;j<8;j++) {

            if(v[2] == lookup[j])
              return true;
          }
        }
      }
    }
  }
  return false;
}

int instByteSize(string str) {

  int i;
  string one[] = {"MOV", "XCHG", "ADD", "SUB", "INR", "DCR", "INX", "DCX", "DAD", "CMA", "CMP", "HLT"};
  string two[] = {"MVI", "ADI", "SUI"};
  string three[] = {"JMP", "JC", "JNC", "JZ", "JNZ", "LDA", "STA", "LHLD", "SHLD", "LXI"};
  string four[] = {"SET"};
  for(i=0;i<12;i++) {

    if(str == one[i])
      return 1;
  }
  for(i=0;i<4;i++) {

    if(str == two[i])
      return 2;
  }
  for(i=0;i<10;i++) {

    if(str == three[i])
      return 3;
  }
  if(str == four[0])
    return 4;
  return -1;
}

bool validInst(string str) {

  int len = str.length(), instSize;
  string temp = "";
  vector<string> v;
  //start
  int p = str.find(' ');
  if(p == -1) {

    v.push_back(str);
  }
  else {

    temp = "";
    for(int i=0;i<p;i++) {

      temp += str[i];
    }
    v.push_back(temp);
    temp = "";
    int q = str.find(',');
    if(q == -1) {

      int r = str.find(' ', p+1);
      if(r == -1) {

        for(int i=p+1;i<str.length();i++) {

          temp += str[i];
        }
        v.push_back(temp);
      }
      else {

        for(int i=p+1;i<r;i++) {

          temp += str[i];
        }
        v.push_back(temp);
        temp = "";
        for(int i=r+1;i<str.length();i++) {

          temp += str[i];
        }
        v.push_back(temp);
      }
    }
    else {

      for(int i=p+1;i<q;i++) {

        temp += str[i];
      }
      v.push_back(temp);
      temp = "";
      for(int i=q+1;i<str.length();i++) {

        temp += str[i];
      }
      v.push_back(temp);
    }
  }
  //end
  instSize = instByteSize(v[0]);
  // cout << instSize << endl;
  switch(instSize) {

    case 1:
      if(oneByte(v))
        return true;
    case 2:
      if(twoByte(v))
        return true;
    case 3:
      if(threeByte(v))
        return true;
    case 4:
      if(fourByte(v))
        return true;
    default:
      return false;
  }
  return false;
}

// int main() {

//   int i;
//   string str;
//   for(i=0;i<5;i++) {

//     getline(cin, str);
//     transform(str.begin(), str.end(), str.begin(), ::toupper);
//     if(validInst(str))
//       cout << "true" <<  endl;
//     else
//       cout << "false" << endl;
//   }
//   return 0;
// }
