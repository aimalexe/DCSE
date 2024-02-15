# Q NO 1: Load a value from memory and add 10 to it. Store the result back in memory and show the result on console. ( hint: use MIPS instructions lw and sw)

.text
.globl main

main:
    # display message
    li $v0, 4       
    la $a0, before
    syscall

    # load the word
    lw $t0, num

    # display the number
    li $v0, 1
    move $a0, $t0
    syscall
    
    addi $t1, $t0, 10

    # store the value
    sw $t1, num

    # display the message
    li $v0, 4       
    la $a0, after
    syscall

    # display the stored value
    li $v0, 1
    move $a0, $t1
    syscall

    j end

    end:
        li $v0, 10	# Exit the program
        syscall


.data
    num: .word 21
    before: .asciiz "The loaded value is: "
    after: .asciiz "\nThe stored value is: "