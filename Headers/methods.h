#ifndef _METHODS_H
#define _METHODS_H

#include "headers.h"

struct elements {

  string pc;
  string start;
  string registers[7];
  map<string, string> memory;
  int flags[8];
  vector<string> breakPoints;
};

int add(elements *);
int adi(elements *);
int dad(elements *);
int dcr(elements *);
int dcx(elements *);
int inr(elements *);
int inx(elements *);
int sub(elements *);
int sui(elements *);

int jc(struct elements *);
int jmp(struct elements *);
int jnc(struct elements *);
int jnz(struct elements *);
int jz(struct elements * );

int lda(struct elements *);
int lhld(struct elements *);
int lxi(struct elements *);
int mov(struct elements *);
int mvi(struct elements *);
int shld(struct elements *);
int sta(struct elements *);
int xchg(struct elements *);

int cma(elements *);
int cmp(elements *);

bool* binAdd(bool*, bool*, elements*);
bool* binSub(bool*, bool*, elements*);
int debug(elements*);
void display(elements *);
int execute(elements *);
int sett(struct elements *);
bool* ToBin(string);
int ToDec(string);
string ToHex(bool*);
int updatePc(elements *);
bool validAddress(string);
bool validInst(string);

int convert2int(char);
char convert2char(int);
string addPc(string ,string);
int instSize(string);
bool val16(string);
bool val8(string);
bool threeByte(vector<string>);
bool twoByte(vector<string> );
bool oneByte(vector<string> );
int instByteSize(string );

void setValues(struct elements *);
void getStart(struct elements *);
void input(struct elements *);
void inputFromFile(struct elements *, string);

void execDebug(elements *);

#endif
