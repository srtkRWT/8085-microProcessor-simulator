This is a simulator for the 8085 microprocessor.


To the run the simulator on linux or mac systems:

1) Open the current directory in terminal

2) Enter the following command in terminal to build the project makefile : 
		make

3) To run the build use the following command : 
		./simulator

4) Once the work is done the following command can be used to clean the '.o' files : 
		make clean

Format for instructions : 

1) Any memory location which will be used as input source for the program will have to initialsed first
	This will be done by using the set command provided in the instruction set.
		example : if memory location 2050 has to be used the command would be :
			SET 2050,10
		where 10 is data in hexadecimal format stored at location 2050

  Note : The instruction 'SET' will be stored as a 4 byte instruction 
	 so the rest of the addresses provided in the code have to be set accordingly
