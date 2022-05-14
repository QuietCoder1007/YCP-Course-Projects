# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl ece260_main			# makes the main label accessible from other files

####################################################################################
# A >= operator
####################################################################################

.text
initialize:
	# insert your initialization instructions here
	li $t0, 7

ece260_main:
	# insert your other instructions here
	# indent your instructions just as this comment is indented
	slti $t2, $t0, 17 # if t0 < 17 set 1 to t2 else 0
	beq $t2, 0 ELSE   # if t2 = 0 jump to else
	li $t3, 10	  # load 10 in to t3
	add $t0, $t0, $t3 # add t0 and t3 and load sum in to t0
	j EXIT		  # Jump to exit
ELSE:	li $t3, 3	  # load 3 in to t3
	sub $t0, $t0, $t3 # subtract t0 and t3 and load difference in to t0
EXIT:
