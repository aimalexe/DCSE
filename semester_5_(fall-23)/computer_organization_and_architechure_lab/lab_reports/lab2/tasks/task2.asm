# Q NO 2: Check whether a number input by user is negative or equal to zero or greater then zero using branching ( Use bgt or ble ).

.text
.globl main

main:
	li $v0, 4 #print string
	la $a0, prompt
	syscall

	li $v0, 5 # enter an int
	syscall
	move $t0, $v0

	li $t1, 0 # store a zero in t1

	# if a number is positive
	bgt $t0,$t1, isPositive

	# if a number is zero
	beq $t0, $t1, isZero

	# if a number is negative
	blt $t0, $t1, isNegative


  # Some branchings
	isPositive:
		li $v0, 4 #print string
		la $a0, positive
		syscall
		j end	# Jump to end

	isZero:
		li $v0, 4 #print string
		la $a0, zero
		syscall
		j end

	isNegative:
		li $v0, 4 #print string
		la $a0, negative
		syscall
		j end

	end:
		li $v0, 10	# Exit the program
		syscall
	
	
.data
	prompt: .asciiz "Enter any Integer? "
	positive: .asciiz "The number is positive "
	zero: .asciiz "The number is zero "
	negative: .asciiz "The number is negative "