# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl initialize ece260_main fib

####################################################################################
.data
	# this section can remain empty for this part
####################################################################################

.text
initialize:
	li $s0, 11			# provide some initial value for n

ece260_main:
	#
	move $a0, $s0
	jal fib
	move $s1, $v0
	#
	j exitProgram			# jump to exit label to terminate program


####################################################################################
# Create a recursive procedure to compute Fibonacci numbers
####################################################################################
fib:
	# Adjust stack as necessary and store preserved registers
	addi $sp, $sp, -12
	sw $ra, 0($sp) 		# return address
	sw $a0, 4($sp) 		# argument (n)
	
	# Base case code
	slti $s2, $a0, 2 	# is n less than 2?
	beq $s2, 0, LOOP 	# if 1, jump to LOOP label
	add $v0, $a0, $zero 	# Return n (assign n to v0)

	# return to caller
	j EXIT
	
	# Recursive case code
LOOP:	subi $a0, $a0, 1 	# (n – 1)
	add $s3, $a0, $zero
	
	sw $a0, 4($sp)
	
	subi $a0, $a0, 1 	# (n – 2)
	add $v0, $a0, $s3
	
	j fib
EXIT:
	# Restore preserved registers and restore stack point
	lw $ra, 0($sp)
	sw $a0, 4($sp) 		# argument (n)
	addi $sp, $sp, 12 	# free memory
	
####################################################################################
exitProgram:
####################################################################################
