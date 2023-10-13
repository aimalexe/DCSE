.text
.globl main
		
main:
	li $v0, 4       # syscall 4 (print_str)
        la $a0, prompt1     # argument: string
        syscall         # print the string
		
	li $v0,5
	syscall
	move $t0,$v0
		
	li $v0,4
	la $a0, prompt2
	syscall
		
	li $v0,5
	syscall
	move $t1,$v0
		
	li $v0,4
	la $a0, low
	syscall
		
	mult $t0,$t1
	li $v0, 1
	mfhi $t3
	syscall
		
	li $v0,4
	la $a0, high
	syscall
		
	mult $t0,$t1
	li $v0, 1
	mflo $t4
	syscall
		
		
.data
	prompt1:   .asciiz "Enter first value? "
	prompt2:   .asciiz "Enter second value? "
	low:   .asciiz "The low register bit is: "
	high:   .asciiz "\nThe high register bit is: "