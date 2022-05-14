# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl ece260_main			# makes the main label accessible from other files

####################################################################################
# A <= operator
####################################################################################

.text
initialize:
	# insert your initialization instructions here
	li $t0, 7
	li $t1, 13

ece260_main:
	# insert your other instructions here
	# indent your instructions just as this comment is indented
	slt $t2, $t1, $t0
	beq $t2, 1, ELSE
	li $t3, 5
	sub $t0, $t0, $t3
	j EXIT
ELSE: 	li $t3, 2 
	sub $t0, $t0, $t3
EXIT:	