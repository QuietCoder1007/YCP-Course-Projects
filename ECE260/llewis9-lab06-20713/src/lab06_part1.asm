# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl initialize ece260_main binary_search exitProgram len nums_array

####################################################################################

.data
	len:         .word  21
	nums_array:  .word  2, 3, 5, 7, 9, 11, 13, 15, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71

####################################################################################

.text
initialize:
	lw $s0, len			# load the length of array into $s0
	la $s1, nums_array		# load the base address of nums_array into $s1
	li $s2, 53			# search for this value

ece260_main:
	move $a0, $s1		# $a0 = nums_array base address ($s1)
	move $a1, $s2		# $a1 = key ($s2) 
	move $a2, $0		# $a2 = min ($0)
	addi $a3, $s0, -1	# $a3 = max ($s0 - 1)
	jal  binary_search
	move $s3, $v0		# load final result into $s3
	j   exitProgram		# jump to exit label to terminate program



####################################################################################
# Create a recursive procedure to perform a binary search
####################################################################################
binary_search:
	bge $a3, $a2, loop	# branch to loop if max >= min
	li $v0, -1	# return -1 for base case
	jr $ra
	
loop:	
	addi $sp, $sp, -4	# Move stack up 4
	sw $ra, 0($sp)		# Save return address
	
 	add $t0, $a3, $a2  	# t0 = min + max
	div $t0, $t0, 2	   	# t0 = (min + max) / 2

	sll $t1, $t0, 2		# shift t0 by 2 bits and load to t1   
	add $t1, $t1, $a0  	# a[mid]
	lw $t1, 0($t1)		# load a[mid] to $t1
	
	bgt $t1, $a1, key_lo	# if a[mid]($t1) > key($a1), branch to key_lo
	blt $t1, $a1, key_hi	# if a[mid]($t1) < key($a1), branch to key_hi
	beq $t1, $a1, key_eq	# if a[mid]($t1) = key($a1), branch to key_eq
	
key_lo:
	addi $a3, $t0, -1	# max = mid - 1
	
	jal binary_search	# return binary_search	!-- function not complete
	j exit			# go to exit to restore stack
key_hi:
	addi $a2, $t0, 1	# min = mid + 1
	
	jal binary_search	# return binary_search	!-- function not complete	
	j exit			# go to exit to restore stack
key_eq:
	move $v0, $t0		# return mid !-- function complete
	
	j exit			# go to exit to restore stack
exit:
	lw $ra, 0($sp)		# load $ra reg
	addi $sp, $sp, 4	# pop stack
	jr $ra			# go to return address

####################################################################################
exitProgram:
####################################################################################

