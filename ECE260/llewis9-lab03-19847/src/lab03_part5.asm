# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl ece260_main end nums array flag	# make these labels accessible from other files for testing

####################################################################################

.data
	# insert your data values here (arrays, strings, variables, etc.)
	# indent your data values just as this comment is indented
	nums: .word 1 3 5 7 9
	array: .space 5
	flag: .word 0xDEADBEEF
	

####################################################################################

.text
ece260_main:
	# insert your instructions here
	# indent your instructions just as this comment is indented
	# stylistically, this indentation will make more sense later
	la $s0, nums
	la $s1, array
	add $s3, $s0, $0
	addi $s3, $s3, 3
	sw $s3, $s1
	
	la $s2, 4(nums)
	la $s1, 0(array)
	add $s3, $s2, $$s0
	addi $s3, $s3, 3
	sw $s3, $s1
	
	la $s4, 8(nums)
	la $s1, 4(array)
	add $s3, $s4, $2
	addi $s3, $s3, 3
	sw $s3, $s1
	
	la $s5, 12(nums)
	la $s1, 8(array)
	add $s3, $s5, $s4
	addi $s3, $s3, 3
	sw $s3, $s1
	
	la $s6, 16(nums)
	la $s1, 12(array)
	add $s3, $s6, $s5
	addi $s3, $s3, 3
	sw $s3, $s1



####################################################################################
end:	# don't put any code after this label, and DO NOT DELETE THIS LABEL
####################################################################################
