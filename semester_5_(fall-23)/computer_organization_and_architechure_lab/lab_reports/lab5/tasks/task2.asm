# Repeat the above problem and display the largest two prime numbers lower than itself. Hint: If a user enters 20, then program displays 19 and 17.

.text
.globl main

main:
    # Show the prompt
    li $v0, 4
    la $a0, prompt
    syscall

    # Take the number $t0=n from the user
    li $v0, 5
    syscall
    move $t0, $v0

    # Initialize $t5 to 2 for the isPrime function
    li $t5, 2

    # Find the largest two prime numbers lower than n
    find_primes:
        addi $t0, $t0, -1 

    # Check if $t0 is less than 2 (end of search)
    blez $t0, exit

        # Call isPrime function with $t0 as the argument
        move $a0, $t0
        jal isPrime

        # Check if $v0 (result from isPrime) is 1 (prime)
        beq $v0, $zero, find_primes

        # If $v0 is 1, we found a prime, store it in $t1 and check for the second prime
        move $t1, $t0  # Store the first prime in $t1
        addi $t0, $t0, -1  # Decrement n by 1 to continue searching

        # Call isPrime function with $t0 as the argument
        move $a0, $t0
        jal isPrime

        # Check if $v0 (result from isPrime) is 1 (prime)
        beq $v0, $zero, exit  # If not prime, exit

        # If $v0 is 1, we found the second prime, store it in $t2 and exit
        move $t2, $t0
        j exit

    # isPrime function
    isPrime:
        li $t3, 2  # Initialize $t3 to 2

        # Check if n < 2
        blt $a0, $t3, notPrimeNumber

        # Calculate n/2 and store it in $t4
        div $a0, $t3
        mflo $t4

        # Loop from 2 to n/2
        isPrimeLoop:
            div $a0, $t3
            mfhi $t6

            beq $t6, $zero, notPrimeNumber

            addi $t3, $t3, 1  # Increment the index

            ble $t3, $t4, isPrimeLoop  # Check to continue the loop

        # Number is prime, set $v0 to 1
        li $v0, 1
        j isPrimeExit

    notPrimeNumber:
        # Number is not prime, set $v0 to 0
        li $v0, 0

    isPrimeExit:
        jr $ra  # Return to the caller

    exit:
        # Display the largest two prime numbers
        li $v0, 4
        la $a0, primeResult1
        syscall

        li $v0, 1
        move $a0, $t1
        syscall

        li $v0, 4
        la $a0, primeResult2
        syscall

        li $v0, 1
        move $a0, $t2
        syscall

        # Exit the program
        li $v0, 10
        syscall

.data
    prompt: .asciiz "Enter a positive number? "
    primeResult1: .asciiz "\nThe largest prime number lower than n is: "
    primeResult2: .asciiz "\nThe second largest prime number lower than n is: "
