# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl initialize ece260_main swap minIndex recursiveSelectionSort exitProgram len nums_array

####################################################################################

.data
	len:         .word 6
	nums_array:  .word 3, 1, 5, 2, 7, 4

####################################################################################

.text
initialize:
	lw $s0, len			# load the length of array into $s0
	la $s1, nums_array		# load the base address of nums_array into $s1
	
ece260_main:
	
	move $a0, $s1			# a0 = nums_array
	move $a1, $s0			# a1 = len
	move $a2, $0			# a2 = 0
	
	jal recursiveSelectionSort
	
	j    exitProgram		# jump to exit label to terminate program
	


####################################################################################
# Create a procedure to swap values within an array (swap contents of two indices)
####################################################################################
swap:
	sll $t0, $a1, 2		# shift t0 by 2 bits and load to t1   
	add $t0, $t0, $a0  	# a[i]
	lw $t2, 0($t0)		# load a[i] to $t1

	sll $t1, $a2, 2		# shift t0 by 2 bits and load to t2  
	add $t1, $t1, $a0  	# a[j]
	lw $t3, 0($t1)		# load a[j] to $t2
	
	sw $t3, 0($t0)		# a[i] = a[i]
	sw $t2, 0($t1)		# a[j] = a[i]
	
	jr $ra

####################################################################################
# Create a recursive procedure that finds the minimum index
####################################################################################
minIndex:
	bne $a1, $a2, loop	# i == j  
	move $v0, $a1		# return i
	jr $ra			# jump to caller

loop:
	addi $sp, $sp, -12	# Move stack up 8
	sw $ra, 0($sp)		# Save return address
	sw $a0, 4($sp)		# Save nums_array
	sw $a1, 8($sp)		# Save i
	
	addi $a1, $a1, 1	# k = (a (a0), len (a1) + 1, j (a2)
	
	jal minIndex		# call minIndex
	
	lw $a0, 4($sp)		# Get a0 back just in case
	lw $a1, 8($sp)		# Get a1 back just in case		
	
	sll $t4, $a1, 2		# shift t4 by 2 bits and load to t1   
	add $t6, $t4, $a0  	# a[i]
	lw $t6, 0($t6)		# load a[i] to $t1
	
	sll $t5, $v0, 2		# shift t5 by 2 bits and load to t2  
	add $t7, $t5, $a0  	# a[k]
	lw $t7, 0($t7)		# load a[k] to $t2
	
	bge $t6, $t7, exit
	move $v0, $a1		# return i if a[i] < a[k]
exit:	
	lw $ra, 0($sp)		# load $ra reg
	addi $sp, $sp, 12	# pop stack
	jr $ra			# go to return address

####################################################################################
# Create the recursiveSelectionSort procedure 
####################################################################################
recursiveSelectionSort:
	bne $a1, $a2, swap_loop
	jr $ra
swap_loop:
	addi $sp, $sp, -16	# Move stack up 8
	sw $ra, 0($sp)		# Save return address
	sw $a0, 4($sp)		# Save nums_array
	sw $a1, 8($sp)		# Save i
	sw $a2, 12($sp)		# Save j
	
	addi $t8, $a1, -1	# t8 = len - 1
	move $a1, $a2		# a1 = index
	move $a2, $t8 		# a2 = t8
	jal minIndex		# call minIndex
	
	lw $a0, 4($sp)		# get a0 back just in case
	lw $a1, 8($sp)		# get a1 back just in case
	lw $a2, 12($sp)		# get a2 back just in case
	
	beq $v0, $a2, rec_loop	# if k == len - 1 recursiveSelectionSort

	move $a1, $v0		# pass k into Swap
	
	jal swap		# call swap
rec_loop:
	lw $a0, 4($sp)		# get a0 back just in case
	lw $a1, 8($sp)		# get a1 back just in case
	lw $a2, 12($sp)		# get a2 back just in case
	
	addi $a2, $a2, 1	# pass in len + 1 into recursiveSelectionSort
	jal recursiveSelectionSort # call recursiveSelectionSort
	
	lw $ra, 0($sp)		# load $ra reg
	addi $sp, $sp, 16	# pop stack
	jr $ra			# go to return address
	
####################################################################################
exitProgram:
####################################################################################
