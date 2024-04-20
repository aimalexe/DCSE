ORG 0x0000      ; Set the origin address

MAIN:           ; Main program label
    MOV A, #1       ; Initialize A register with 00000001
    MOV R1, #8      ; Initialize R1 with 8, representing 8 iterations
    
LOOP:
    MOV P1, A       ; Output A to Port 1
    ACALL DELAY     ; Call delay subroutine
    //MOV A, A        ; Move A to itself, no operation
    MOV P1, #0      ; Turn off all LEDs
    ACALL DELAY     ; Call delay subroutine
    INC A           ; Increment A to shift the pattern to the left
    DJNZ R1, LOOP   ; Decrement R1 and loop if it's not zero
    SJMP MAIN       ; Jump back to main to repeat the pattern

DELAY:
    ; Insert delay subroutine here (based on your clock frequency)
    RET
END