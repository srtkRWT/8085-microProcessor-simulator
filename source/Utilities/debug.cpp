#include "headers.h"
#include "methods.h"

int debug(elements *e)
{
	e->pc = e->start;
	cout<<"DEBUGGER MODE ON :\ntype \"help\" for help\n\n";
	map<int, int > breakPt;
	int line=0,end=0;
	while(1)
	{
		string input,cmd;
		int lineNo;
		cout<<"debug:";
		fflush(stdin);
		getline(cin,input);
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		stringstream inputstream(input);
		inputstream >> cmd;
		if(cmd == "B" ||cmd == "b")
		{
			int lineNo;
			inputstream >> lineNo; 
			breakPt[lineNo]=1;
		}
		else if(cmd == "R"||cmd == "r")
		{
			while(end==0 && breakPt.find(line) == breakPt.end() )
			{
				cout<<e->memory[e->pc ]<<endl;
				
				if(e->memory[e->pc ]=="HLT"){
					line++;
					end=1;
					break;
				}
				execDebug(e);
				line++;
			}
		}
		else if(cmd == "S"||cmd == "s")
		{
			if(end == 0)
			{
				cout<<e->memory[e->pc ]<<endl;
				if(e->memory[e->pc ] == "HLT")
				{
					end=1;
				}
				execDebug(e);
				line++;
				
			}
			else
				cout<<"THATS ALL FOLKS\n";
		}
		else if(cmd == "P"||cmd == "p")
		{
			string arg;
			inputstream.ignore() ;
			inputstream >>arg;
			if(arg[0] == 'A'||arg[0] == 'B'||arg[0] == 'C'||arg[0] == 'D'||arg[0] == 'E'||arg[0] == 'H'||arg[0] == 'L')
			{
				cout<<"register "<<arg[0]<<":"<<e->registers[arg[0]-'A']<<endl;
			}
			else if(arg[0]== 'x'||arg[0]== 'X')
			{
				arg = arg.substr(1);
				cout<<"memory "<<arg<<":"<<e->memory[arg]<<endl;
			}
		}
		else if(cmd == "Q"||cmd == "q")
		{
			return 0;
		}
		else if(cmd == "HELP"||cmd == "help")
		{
			cout<<"1. break or b `line no`:- It will set break point on given line number.\n2. run or r :- Run the program until it ends or breakpoint is encountered.\n3. step or s :- It will run the program one instruction at a time.\n4. print or p:- It prints the value of register or memory location. for ex p A will print the value ofregister A. p x2500 will print the value at memory location x2500 if any.\n5. quit or q:- quits the debugger.\n6. help:- will show all the commands of debugger."<<endl;
		}
		else
			cout<<"*invalid*\n";
	}
	return 0;
}
