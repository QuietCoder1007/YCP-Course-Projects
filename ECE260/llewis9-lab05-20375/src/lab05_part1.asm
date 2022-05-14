# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl initialize ece260_main multiply divide

####################################################################################
.data
	# this section can remain empty for part #1
####################################################################################

.text
j initialize		# start by jumping to initialize


####################################################################################
# multiply procedure accepts two arguments and returns $a0 * $a1
####################################################################################
multiply:
	# insert your multiply procedure here
	mul $v0, $a0, $a1 
	jr $ra
	
####################################################################################
# divide procedure accepts two arguments and returns $a0 / $a1
####################################################################################
divide:
	# insert your divide procedure here	
	div $v0, $a0, $a1 
	jr $ra


####################################################################################
# FOr the following equation, F = (3 * X) / (Y * Z), compute the value of F
# Do not use the mul/div instructions within the main procedure
####################################################################################
initialize:
	li $s0, 3 	# provide some initial value for X (you can change these)
	li $s1, 4 	# provide some initial value for Y
	li $s2, 5 	# provide some initial value for Z

ece260_main:
	# write the rest of your implementation here to 
	addi $a0, $0, 3
	add $a1, $s0, $0
	jal multiply
	
	add $t0, $v0, $0
	
	add $a0, $s1, $0
	add $a1, $s2, $0
	jal multiply
	
	add $t1, $v0, $0
	
	add $a0, $t0, $0
	add $a1, $t1, $0
	jal divide
	
	add $s3, $v0, $0
