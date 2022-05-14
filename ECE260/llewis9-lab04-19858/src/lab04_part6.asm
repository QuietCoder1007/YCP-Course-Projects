# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl initialize loop end len nums

####################################################################################

.data
	# insert your data values here (arrays, strings, variables, etc.)
	# indent your data values just as this comment is indented
	len: .word 6
	nums: .word 3 4 5 6 7 8
####################################################################################

.text
initialize:
	# insert your initialization instructions here
	# initialize the registers for len, the nums base address, i, and sum here
	la $s3, len	# len word address
	lw $s0, ($s3)	# len variable
	la $s1, nums 	# nums array
	li $t0, 0	# sum variable
	li $t1, 0	# i variable
	
loop:
	# insert your loop instructions here
	# you may find it necessary to create an additional label
	bge $t1, $s0, EXIT
	
	lw $s3, ($s1)		# Load word s3
	add $t0, $t0, $s3	# Add (s3)value in address to sum(t0)
	add $s1, $s1, 4		# Shift nums array base address by 4
	
	addi $t1, $t1, 1	# Increment t1(i) by 1
	
	j loop
EXIT:	div $s2, $t0, $s0	# Divide t0(sum) by s0(len) and load into s2(average) 




####################################################################################
end:	# don't put any code after this label
####################################################################################
