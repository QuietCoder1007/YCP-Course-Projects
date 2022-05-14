# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl ece260_main			# makes the main label accessible from other files

####################################################################################
# Use the SLT instruction
####################################################################################

.text
initialize:
	li $t0, 3			# load 'value' into a register
	li $t1, 5			# load '5' into a register for a comparison
	
ece260_main:
	# insert your other instructions here
	# indent your instructions just as this comment is indented
	slt $t2, $t0, $t1
	beq $t2, $0, ELSE
	addi $t0, $t0, 7
	j EXIT
ELSE: 	addi $t0, $t0, 9
EXIT:	
