	.ORIG X3000
	AND R0, R0, #0
	AND R7, R7, #0
	LEA R7, ADS
	LD R3, COUNT
LOOP
	ADD R7, R7, #1
	TRAP X23 ;take input from user
	STR R0, R7, #0 ;store input to R0
	ADD R7, R7, #1 ; add one to R7 address
	ADD R3, R3, #-1 ; decrement R3
	BRnp LOOP
	;
	LDR R1, R7, #0 ;store input into R1
	LDR R2, R7, #1 ; store another input into R2
	NOT R2, R2
	ADD R2, R2, #1
	ADD R4, R1, R2 ; R4=R1-R2
	BRnz SMALL	; R4<=0
	STR R2, R7, #0 ; swap X and X+1
	STR R1, R7, #1 ;
SMALL	HALT
	;
	ADS	.FILL X3110
	COUNT	.FILL #1
	.END