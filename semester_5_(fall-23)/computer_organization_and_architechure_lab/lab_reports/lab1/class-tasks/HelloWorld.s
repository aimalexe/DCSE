	.text
	.globl main

main:
	li $v0, 4
	la $a0, msg
	syscall

	li $v1, 10
	syscall

	.data
msg:	.asciiz "Hello World"
	.extern foobar 4
	