MOV TMOD, #20H  ; Timer 1 in mode 2
MOV TH1, #0FAH  ; buad rate of 4800
MOV SCON, #40H  ; transmission in mode 1
SETB TR1

MOV A, #00H
MOV DPTR, #LOOKUP
MOV B, #00H
LOOP: MOVC A, @A+DPTR
MOV SBUF, A   ; sending character
JNB TI, $     ; waiting for transmission
CLR TI     ; reseting the flag
INC B
MOV A, B
CJNE A, #06, LOOP
JMP FINISH


LOOKUP:
DB "Aditya"

FINISH:
END
