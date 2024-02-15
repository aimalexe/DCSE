# Q NO 5: Write a program which take a limit from user and compute the sum of numbers from to the limit ( Use bqe, add, addi, and J (jump))

.text
.globl main

main:
	li $v0, 4 #print string
	la $a0, prompt
	syscall

	li $v0, 5 # enter an int num
	syscall
	move $t0, $v0

	
	li $t1, 1 # store 1
	li $t2, 2 # store 2

	# if num > 0
	bgt $t0, $zero, countSum

	# else num <= 0
	ble $t0, $zero, noSum


  	# -------------- Some branchings -----------------
	countSum:	# n(n+1)/2
		add $t3, $t0, $t1	# n+1
		mul $t4, $t0, $t3	# n(n+1)
		div $t4, $t2	# n(n+1)/2		
		mflo $t5	# save qoutient
		
		li $v0, 1
		move $a0, $t5
		syscall		

		j end

	noSum:
		li $v0, 4
		la $a0, errorMessage
		syscall
		
		j end

	end:
		li $v0, 10	# Exit the program
		syscall

.data
	prompt: .asciiz "Enter a number? "
	errorMessage: .asciiz "Cannot count sum of zero or negative numbers!"

