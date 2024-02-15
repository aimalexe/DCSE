# Q NO 3: Load an address of a label into a register and jump to that address and perform addition in that address. .(use jr(jump register) )

.text
.globl main

main:
    la $t0, additionLabel # load label to register
    jr $t0 # jump to the label

    additionLabel:
        li $t1, 75
        li $t2, 68
        add $t3, $t1, $t2

        # print the message
        li $v0, 4
        la $a0, result
        syscall

        # print the integer
        li $v0, 1
        move $a0, $t3
        syscall

        j end

    end:
        li $v0, 10	# Exit the program
        syscall

.data
    result: .asciiz "The sum is: "