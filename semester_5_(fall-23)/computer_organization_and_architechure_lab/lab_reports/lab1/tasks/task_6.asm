.text
.globl main
		
main:   
	li $v0, 4       
        la $a0, prompt1     
        syscall         
		
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
	la $a0, AND
	syscall
		
	and $t2,$t0,$t1
	li $v0, 1
	move $a0, $t2
	syscall
		
	li $v0,4
	la $a0, OR
	syscall
	
	or $t3,$t0,$t1
	li $v0, 1
	move $a0, $t3
	syscall
		
	li $v0,4
	la $a0, NOT
	syscall
	
	not $t4,$t0
	li $v0, 1
	move $a0, $t4
	syscall
		
		
.data
	prompt1:   .asciiz "Enter first value? "
	prompt2:   .asciiz "Enter second value? "
	AND:   .asciiz "Result of AND: "
	OR:   .asciiz "\nResult of OR: "
	NOT:   .asciiz "\nResult of NOT: "