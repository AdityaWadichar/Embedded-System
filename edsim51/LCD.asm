CLR P0.3 ; CLEAR RS
MOV P1, #38H; Function set (2 line 
SETB P0.2; Set EN high
CALL DELAY
CLR P0.2; Clear EN
MOV P1, #0EH ; cursor and display on
SETB P0.2
CALL DELAY
CLR P0.2
MOV P1, #06H ; move cursor
SETB P0.2
CALL DELAY
CLR P0.2

SETB P0.3

; the string to be displayed is in lookup table
MOV A, #00H
MOV DPTR, #LOOKUP
MOV B, #00H
LOOP: MOVC A, @A+DPTR
MOV P1,A
SETB P0.2
CALL DELAY
CLR P0.2
INC B
MOV A, B
CJNE A, #16, LOOP
RET

DELAY:
MOV R0, #0F0H
DJNZ R0, $
RET

LOOKUP:
DB "Aditya Wadichar"
