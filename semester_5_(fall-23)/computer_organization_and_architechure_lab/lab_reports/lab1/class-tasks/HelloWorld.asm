    .text
    .globl main


main:
    li $v0, 4
    la $a0, prompt1
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 4
    la $a0, prompt2
    syscall

    li $v0, 5
    syscall
    move $t1, $v0
    
    li $v0, 4
    la $a0, prompt3
    syscall

    add $t2, $t1, $t0
    li $v0, 1
    move $a0, $t2
    syscall

    li $v0, 10
    syscall

    .data
prompt1:     .asciiz "Enter a numbers___\n"
prompt2:     .asciiz "Enter another numbers___\n"
prompt3:     .asciiz "The sum of these number is: "