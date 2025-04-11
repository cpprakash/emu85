;taken from https://collegeek.com/8085_microprocessor/example.html
MVI A,A9H     ; Loads the  A9h to Accumulator
MVI B,ABH     ; Loads the  ABh to B-register 
MVI C,00H     ; Loads the  00h to C-register  
SUB B         ; Subtract the content of B-register from Accumulator and result stored in Accumulator. 
JNC SKIP      ; Jump on no Carry to SKIP 
INR C         ; Increment C-register  
CMA           ; Complements Accumulator content 
INR A         ; Increment Accumulator  
SKIP: STA 2100H     ; Stores the answer to memory location 2100 H 
    MOV A,C       ; moves the content of C-register to accumulator (A < - C) 
    HLT           ; Stop processing