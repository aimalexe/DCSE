# Q NO 2: Write a program that’s show the bit position of a number is 0 or 1. (Hint if number is 5 it is represented by 0101 show the 4th bit position is 0, similarly if the user enters 9 then the binary equivalent is 1001. In this case the 4th bit position is 1).

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

    # Check the 4th bit:
        #   To check whether the 4th bit is 0 or 1, we use a bitwise AND operation. We load the value 0x08 into $t1, which is the binary representation of 0000 1000. This value has all bits set to 0 except the 4th bit.
        #   We then perform an AND operation between the user input $t0 and the mask $t1. If the 4th bit of $t0 is 1, the result of the AND operation will be non-zero. If it's 0, the result will be 0.
    li $t1, 0x08
    and $t0, $t0, $t1
    bnez $t0, bit_is_1

    # If the 4th bit is 0
    li $v0, 4
    la $a0, result0
    syscall
    j exit

bit_is_1:
    # If the 4th bit is 1
    li $v0, 4
    la $a0, result1
    syscall

exit:
    # Exit the program
    li $v0, 10
    syscall


.data
    prompt: .asciiz "Enter a number: "
    result0: .asciiz "The 4th bit is 0\n"
    result1: .asciiz "The 4th bit is 1\n"
