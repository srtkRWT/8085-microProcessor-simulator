SET 2050 20
SET 2051 20
LDA 2050
MOV B,A
LDA 2051
SUB B
JZ 2014
INR A
STA 3050
HLT