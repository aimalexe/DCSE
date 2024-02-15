# Q No 5: Show that shifting left of an even number by 1 position is a multiplication by 2 and shifting right of an even number by 1 position is a division by 2. (Hint: Use sll and srl)

.text
.globl main

main:
    # Display the prompt
    li $v0, 4
    la $a0, prompt
    syscall

    # Read user input
    li $v0, 5
    syscall
    move $t0, $v0  # Store the input in $t0

    li $t1, 2 # store 2 in t1

    # shifting to left by 1 bit
    sll $t2, $t0, 1

    li $v0, 4
    la $a0, shiftedLeft
    syscall

    li $v0, 1
    move $a0, $t2
    syscall

    # multiplied by 2
    mul $t3, $t0, $t1

    li $v0, 4       
    la $a0, multAnswer
    syscall 

    li $v0, 1 # print The expression (int) 
    move $a0, $t3
    syscall

    # shifted to right by 1 bit
    srl $t4, $t0, 1

    li $v0, 4
    la $a0, shiftedRight
    syscall

    li $v0, 1
    move $a0, $t4
    syscall

    # division by 2
    div $t5, $t0, $t1

    li $v0, 4       
    la $a0, divAnswer
    syscall 

    li $v0, 1 # print The expression (int) 
    move $a0, $t5
    syscall

    # Exit the program
    li $v0, 10
    syscall
    
.data
    prompt: .asciiz "Enter an even number: "
    shiftedLeft: .asciiz "\nAfter shifting left by one bit: "
    multAnswer: .asciiz "\nMultiplying by two: "
    shiftedRight: .asciiz "\nAfter shifting right by one bit: "
    divAnswer: .asciiz "\nDividing by two: "
