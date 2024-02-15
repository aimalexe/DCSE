# Q NO 2: Load a value from memory and double it. Store the result back in memory also show on the console. (use sll, sw and lw)

.text
.globl main

main:
    # display message
    li $v0, 4       
    la $a0, before
    syscall

    # load the value
    lw $t0, value

    # display the number
    li $v0, 1
    move $a0, $t0
    syscall
     
    # Double the value using sll (shift left logical)
    sll $t1, $t0, 1  # Shift left by 1 bit to double the value
    sw $t1, value

    # display the message
    li $v0, 4       
    la $a0, after
    syscall

    # display the number
    li $v0, 1
    move $a0, $t1
    syscall

    j end
    end:
        li $v0, 10	# Exit the program
        syscall

.data
    value: .word 18
    before: .asciiz "The loaded value: "
    after: .asciiz "\nAfter doubling the value: "