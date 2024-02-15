# Q NO 3: Now toggle the bit find in the previous task if the bit is 1 set it to 0 if it is 0 then set it to 1.

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

    # Toggle the 4th bit
    li $t1, 0x08   # Binary: 0000 1000
    xor $t0, $t0, $t1

    # Display the result
    li $v0, 4
    la $a0, result
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    # Exit the program
    li $v0, 10
    syscall

.data
    prompt: .asciiz "Enter a number: "
    result: .asciiz "After toggling the 4th bit: "