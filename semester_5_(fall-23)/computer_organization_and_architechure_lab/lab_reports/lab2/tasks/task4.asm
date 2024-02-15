# Q NO 4 : Write the assembly of the below C++ code.

.text
.globl main

main:
	li $v0, 4 #print string
	la $a0, prompt
	syscall

	li $v0, 5 # enter an int
	syscall
	move $t0, $v0
	
	li $t1, 18 # load 18 to a register

	# if user >= 18
	bge $t0, $t1, isEighteen

	# if user is not 18
	blt $t0, $t1, isNotEighteen


  	# -------------- Some branchings -----------------
	isEighteen:
		li $v0, 4 #print a string
		la $a0, msg1
		syscall
		j end

	isNotEighteen:
		li $v0, 4 #print a string
		la $a0, msg2
		syscall
		j end
	

	end:
		li $v0, 10	# Exit the program
		syscall

.data
	prompt: .asciiz "Enter Your age? "
	msg1: .asciiz "You can apply for CNIC!"
	msg2: .asciiz "You can't apply for CNIC"

