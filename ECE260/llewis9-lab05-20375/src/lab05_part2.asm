# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl initialize ece260_main multiply power

####################################################################################
.data
	# this section can remain empty for this part
####################################################################################

.text
initialize:
	li $s0, 2			# provide some initial value for base
	li $s1, 3			# provide some initial value for exponent

ece260_main:
	move $a0, $s0
	move $a1, $s1
	jal power
	move $s2, $v0
	
	j exitProgram			# jump to exitProgram label to terminate program
	
	
####################################################################################
# multiply procedure accepts two arguments and returns $a0 * $a1
####################################################################################
multiply:
	# insert your multiply procedure here
	mul $v0, $a0, $a1 
	jr $ra

####################################################################################
# Create a procedure to compute base^exponent
####################################################################################
power:
	# Adjust stack as necessary and store preserved registers
	addi $sp, $sp, -16
	sw $ra, 0($sp)
	sw $s3, 4($sp)
	sw $s4, 8($sp)
	sw $s5, 12($sp)
	# initialize local variables
	li $s1, 1
	move $s3, $a0 
	move $s4, $a1 
	# loop to compute result
LOOP:	slt $s5, $s1, $s4
	beq $s5, $0, EXIT
	move $a0, $s0
	move $a1, $s3
	jal multiply
	move $s0, $v0
	addi $s1, $s1, 1
	# Restore preserved registers and restore stack point
	lw $ra, 0($sp)
	addi $sp, $sp, 16
	j LOOP
	# return to caller
EXIT: 	jr $ra


####################################################################################
exitProgram:
####################################################################################
