ODIR = Objects/

CXX = g++

CXXFLAGS = -IHeaders/ -g

OBJECTS = Objects/add.o Objects/adi.o Objects/dad.o Objects/dcr.o Objects/dcx.o Objects/inr.o Objects/inx.o Objects/sub.o Objects/sui.o \
Objects/jc.o Objects/jmp.o Objects/jnc.o Objects/jnz.o Objects/jz.o \
Objects/lda.o Objects/lhld.o Objects/lxi.o Objects/mov.o Objects/mvi.o Objects/shld.o Objects/sta.o Objects/xchg.o \
Objects/cma.o Objects/cmp.o \
Objects/binAdd.o Objects/binSub.o Objects/debug.o Objects/display.o Objects/execute.o Objects/increment.o Objects/set.o \
Objects/ToBin.o Objects/ToDec.o Objects/ToHex.o Objects/updatePc.o Objects/validAddress.o Objects/validInst.o \
Objects/setValues.o Objects/getStart.o Objects/input.o Objects/inputFromFile.o Objects/execDebug.o \
Objects/convert2int.o Objects/convert2char.o Objects/addPc.o Objects/instSize.o \
Objects/main.o 

SRC = source/Arithmetic/add.cpp source/Arithmetic/adi.cpp source/Arithmetic/dad.cpp source/Arithmetic/dcr.cpp source/Arithmetic/dcx.cpp \
source/Arithmetic/inr.cpp source/Arithmetic/inx.cpp source/Arithmetic/sub.cpp source/Arithmetic/sui.cpp \
source/Branching/jc.cpp source/Branching/jmp.cpp source/Branching/jnc.cpp source/Branching/jnz.cpp source/Branching/jz.cpp \
source/DataTransfer/lda.cpp source/DataTransfer/lhld.cpp source/DataTransfer/lxi.cpp source/DataTransfer/mov.cpp \
source/DataTransfer/mvi.cpp source/DataTransfer/shld.cpp source/DataTransfer/sta.cpp source/DataTransfer/xchg.cpp \
source/Logical/cma.cpp source/Logical/cmp.cpp \
source/Utilities/binAdd.cpp source/Utilities/binSub.cpp source/Utilities/debug.cpp source/Utilities/display.cpp source/Utilities/execute.cpp \
source/Utilities/increment.cpp source/Utilities/set.cpp source/Utilities/ToBin.cpp source/Utilities/ToDec.cpp source/Utilities/ToHex.cpp \
source/Utilities/updatePc.cpp source/Utilities/validAddress.cpp source/Utilities/validInst.cpp \
source/Utilities/setValues.cpp source/Utilities/getStart.cpp source/Utilities/input.cpp source/Utilities/inputFromFile.cpp \
source/Utilities/execDebug.cpp source/Utilities/convert2int.cpp source/Utilities/convert2char.cpp source/Utilities/addPc.cpp \
source/Utilities/instSize.cpp \
source/main.cpp

simulator: $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS)

$(OBJECTS): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC)
	mv *.o $(ODIR)

clean:
	rm $(ODIR)*.o

