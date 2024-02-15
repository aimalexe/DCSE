# Q NO 3: Check using branch whether the number input by user are equal or not ( Use beq ).

.text
.globl main

main:
	li $v0, 4 #print string
	la $a0, prompt1
	syscall

	li $v0, 5 # enter an int
	syscall
	move $t0, $v0

	li $v0, 4 #print string
	la $a0, prompt2
	syscall

	li $v0, 5 # enter an int
	syscall
	move $t1, $v0


	# if a both number are equal
	beq $t0,$t1, isEqual

	# if both number are not equal
	bne $t0, $t1, isNotEqual


	# ------------ Some branchings: -----------------------
	isEqual:
		li $v0, 4 #print string
		la $a0, equal
		syscall
		j end	# Jump to end

	isNotEqual:
		li $v0, 4 #print string
		la $a0, notEqual
		syscall
		j end


	end:
		li $v0, 10	# Exit the program
		syscall
	
	
.data
	prompt1: .asciiz "Enter an Integer? "
	prompt2: .asciiz "Enter another Integer? "
	equal: .asciiz "Both The numbers are Equall."
	notEqual: .asciiz "Both the number are different/not-Equal."
	