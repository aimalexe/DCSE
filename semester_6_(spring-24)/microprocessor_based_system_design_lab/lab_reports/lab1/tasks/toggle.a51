ORG 000h      ; Set the origin address

MAIN:           ; Main program label
	MOV A , #0FFh; Load A with inital 1's
    MOV P1, A   ; Set all pins of Port 1 as output and initially high
    MOV P2, A   ; Set all pins of Port 2 as output and initially high

	MOV A , #000h; Load A with 0's
    MOV P1, A   ; Set all pins of Port 1 as output and initially high
    MOV P2, A   ; Set all pins of Port 2 as output and initially high
    ACALL DELAY     ; Call delay subroutine
    SJMP MAIN       ; Jump back to loop

DELAY:
    ; Insert delay subroutine here (based on your clock frequency)
    RET
END