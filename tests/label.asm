;program to check labels
JMP START
;data
;code
START: NOP
LDA 2050h
MOV H, A
LDA 2051h
ADD H 
MOV L, A 
MVI A, 00h 
ADC A
MOV H, A 
SHLD ff50h 
;another comment

HLT