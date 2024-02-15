# Q NO 4: Write a program to check a number entered by user is even or odd.

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

    # Check the last bit:
    li $t1, 0x01
    and $t0, $t0, $t1
    bnez $t0, bit_is_1

    # If the last bit is 0 it is even
    li $v0, 4
    la $a0, result0
    syscall
    
    j exit

bit_is_1:
    # If the last bit is 1 it is odd
    li $v0, 4
    la $a0, result1
    syscall

exit:
    # Exit the program
    li $v0, 10
    syscall


.data
    prompt: .asciiz "Enter a number: "
    result0: .asciiz "The number is even.\n"
    result1: .asciiz "The number is odd.\n"
