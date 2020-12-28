MOV SCON, #00H  ; transmission in mode 0

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
