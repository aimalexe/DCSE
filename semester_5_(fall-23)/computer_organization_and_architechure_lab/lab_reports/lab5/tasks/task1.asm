# Write a program to check whether a number input by user is prime or not.

.text
.globl main

main:
    # show the prompt
    li $v0, 4
    la $a0, prompt
    syscall

    # take the number $t0=n from user
    li $v0, 5
    syscall
    move $t0, $v0

    # implementation of isPrime function
    isPrime:
        li $t1, 2

        blt $t0, $t1, notPrimeNumberLabel 

        # calculate $t3 = n/2
        div $t0, $t1
        mflo $t3

        # loop from 2 to n/2
        loop:
            div $t0, $t1
            mfhi $t4

            beq $t4, $zero, notPrimeNumberLabel 

            addi $t1, $t1, 1 # increment the index

            ble $t1, $t3, loop # check to continue the loop
        j isPrimeNumberLabel

        notPrimeNumberLabel:
            # show that number is not prime
            li $v0, 4
            la $a0, notPrimeNumberMsg
            syscall

            j Exit

        isPrimeNumberLabel:
            # show that number is prime
            li $v0, 4
            la $a0, isPrimeNumberMsg
            syscall

            j Exit    
    
    Exit:
        li $v0, 10
        syscall


.data
    prompt: .asciiz "Enter a positive number? "
    notPrimeNumberMsg: .asciiz "The Number is not prime!\n"
    isPrimeNumberMsg: .asciiz "The Number is prime!\n"