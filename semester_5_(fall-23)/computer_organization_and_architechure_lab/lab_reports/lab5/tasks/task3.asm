# Write a program which takes two limits from user and display prime numbers between the two limits (if user enter lower limit 10 and upper limit 30 then display prime numbers between 10 and 30)

.text
.globl main

main:
    # show the prompt for lower number
    li $v0, 4
    la $a0, prompt1
    syscall

    # take the number $t0=n1 from user
    li $v0, 5
    syscall
    move $t0, $v0
    
    # show the prompt for upper number
    li $v0, 4
    la $a0, prompt2
    syscall

    # take the number $t1=n2 from user
    li $v0, 5
    syscall
    move $t1, $v0

    # taking loop from n1 to n2
    loopFromLower2Upper:
        bgt $t0, $t1, Exit
        j isPrime

    # implementation of isPrime function
    isPrime:
        li $t2, 2

        blt $t0, $t2, notPrimeNumberLabel

        # calculate $t3 = n/2
        div $t0, $t2
        mflo $t3

        # loop from 2 to n/2
        loop:
            div $t0, $t2
            mfhi $t4

            beq $t4, $zero, notPrimeNumberLabel 

            addi $t2, $t2, 1 # increment the index

            ble $t2, $t3, loop # check to continue the loop
        j isPrimeNumberLabel

        notPrimeNumberLabel:
            # only increment the loop
            addi $t0, $t0, 1

            j loopFromLower2Upper

        isPrimeNumberLabel:
            # show that number is prime
            li $v0, 1
            move $a0, $t0
            syscall

            li $v0, 4
            la $a0, comma
            syscall

            addi $t0, $t0, 1

            j loopFromLower2Upper
    
    Exit:
        li $v0, 10
        syscall

.data
    prompt1: .asciiz "Enter a lower limit number? "
    prompt2: .asciiz "Enter an upper limit number? "
    comma: .asciiz ", "
    