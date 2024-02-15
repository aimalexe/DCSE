# Q NO 1: Take the 1st number from user. Then take a number to do the operation. (1 corresponds to addition, 2 corresponds to subtraction, 3 for multiplication and 4 for division). Then finally take a 2nd number from a user. (use branching i.e beq and j).


.text
.globl main

main:
    # Take a number from user in $t0
    li $v0, 4
    la $a0, prompt1
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    # Take Operator from user in $t1
    li $v0, 4
    la $a0, operationsList
    syscall

    li $v0, 5
    syscall
    move $t1, $v0
    
    # Take another number from user $t2
    li $v0, 4
    la $a0, prompt2
    syscall

    li $v0, 5
    syscall
    move $t2, $v0


    # Making the calculator logic 
    li $t3, 1
    li $t4, 2
    li $t5, 3
    li $t6, 4

    beq $t1, $t3, Addition
    beq $t1, $t4, Subtraction
    beq $t1, $t5, Multiplication
    beq $t1, $t6, Division

    Addition:
        add $t7, $t0,$t2
        j Display_Answer

    Subtraction:
        sub $t7, $t0,$t2
        j Display_Answer
    
    Multiplication:
        mul $t7, $t0,$t2
        j Display_Answer

    Division:
        div $t7, $t0,$t2
        j Display_Answer

    Display_Answer:
        li $v0, 4       
        la $a0, answer
        syscall 

        li $v0, 1 # print The expression (int) 
        move $a0, $t7
        syscall

        j End

    End:
        li $v0, 10	# Exit the program
        syscall
	
	
.data
	prompt1: .asciiz "Enter a number? "
    operationsList: .asciiz "Enter operation:\n1 --> Addition.\n2 -->Subtraction.\n3 -->Multiplication.\n4 -->Division.\n"
	prompt2: .asciiz "Enter another number? "
	answer: .asciiz "The answer is: "