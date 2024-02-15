#  Q-1)Enter a number 5432 from user and then display the last digit in the console. (hint: use mfhi )

.text
.globl main

main:
	li $v0, 4 #print string
	la $a0, prompt
	syscall

	li $v0, 5 # enter an int
	syscall
	move $t0, $v0

	li $t1, 10
	div $t0, $t1
	mfhi $t0

	li $v0, 4
	la $a0, result
	syscall

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 10	# Exit the program
	syscall
	
	
.data
	prompt: .asciiz "Enter 4 digit number? "
	result: .asciiz "The last digit of entered number is: "