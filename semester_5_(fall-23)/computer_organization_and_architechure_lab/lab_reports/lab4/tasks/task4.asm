# Q NO 4: Write assembly program to find the Fibonacci series(0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...).
# Users will be asked to enter a number, for instance 9. Then assembly will print the first 9 numbers of Fibonacci series.

.text
.globl main

main:
    # display prompt and read 'n'
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    # init first and second
    li $t1, 0
    li $t2, 1

    # print first and second with commas
    li $v0, 4
    la $a0, result
    syscall

    li $v0, 1
    move $a0, $t1
    syscall

    li $v0, 4
    la $a0, comma
    syscall

    li $v0, 1
    move $a0, $t2
    syscall

    li $v0, 4
    la $a0, comma
    syscall
    
    # init loop 'i'
    li $t3, 2

    loop:
        add $t4, $t1, $t2 # next = first + second

        # print the sequence with commas
        li $v0, 1
        move $a0, $t4
        syscall

        li $v0, 4
        la $a0, comma
        syscall

        # update i, first and second
        move $t1, $t2
        move $t2, $t4
        addi $t3, $t3, 1

        # exit loop if we have generated n terms
        beq $t3, $t0, end

        j loop


    end:
        li $v0, 10	# Exit the program
        syscall

.data
    prompt: .asciiz "How many terms do you want to print of Fibonacci series? "
    result: .asciiz "Fibonacci series: "
    comma: .asciiz ", "