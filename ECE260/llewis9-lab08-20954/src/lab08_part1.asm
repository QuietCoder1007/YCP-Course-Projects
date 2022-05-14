# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl initialize ece260_main computeError getNextSquareRootApprox squareRoot exitProgram n limit	# make these labels accessible from other files for testing

####################################################################################

.data
	n: 	.double		4096.0
	limit:	.double		0.1
	
####################################################################################

.text
initialize:
	l.d    $f0, n			# load the value that we're rooting into $f1+$f0
	l.d    $f2, limit		# load the value for 'limit' into $f3+$f2
	
ece260_main:
	mfc1.d $a0, $f0			# sets $a1+$a0 with double value stored in $f1+$f0
	mfc1.d $a2, $f2			# sets $a3+$a2 with double value stored in $f3+$f2
	jal    squareRoot		# call squareRoot procedure
	mtc1.d $v0, $f12		# sets $f13+$f12 with double value stored in $v1+$v0
	
	li     $v0, 3			# prepare to make a syscall with code #3 (prints double stored in $f13+$f12)
	syscall				# make system call to print the double stored in $f13+$f12
	
	j exitProgram			# terminate the program


####################################################################################
# Create a procedure to compute the error for each iteration
####################################################################################
computeError:
	
	andi $t0, $sp, 7	# double-word align check
	sub $sp, $sp, $t0	# sub tract diff from stack
	addi $sp, $sp, -16	# subtract space to allocate to stack
	
	s.d $f4, 0($sp)		# Save f4 register
	s.d $f6, 8($sp)		# Save f6 register

####################################################################################
#	Store to stack
####################################################################################
	
	mtc1.d $a0, $f4	 	# a0 + a1 = x_n_plus_one (f4)
	mtc1.d $a2, $f6		# a2 + a3 = x_n (f6)
	
	sub.d $f6, $f4, $f6	# $f6 = x_n_plus_one - x_n
	abs.d $f6, $f6		# $f6 = fabs($f6)
	
	mfc1.d $v0, $f6		# return $f6
	
	l.d $f4, 0($sp)		# load f4 register
	l.d $f6, 8($sp)		# load f6 register

####################################################################################
#	Free stack
####################################################################################
	
	addi $sp, $sp, 16
	add $sp, $sp, $t0
	
	jr $ra



####################################################################################
# Create a procedure that calculates the next approximation of square root: 
#   x_n - ((x_n^2 - n) / (2 * x_n))
####################################################################################
getNextSquareRootApprox:
	
	andi $t0, $sp, 7
	sub $sp, $sp, $t0
	addi $sp, $sp, -24
	
	s.d $f8, 0($sp)		# Save f8 register
	s.d $f10, 8($sp)	# Save f10 register
	s.d $f12, 16($sp)	# Save f12 register
	
####################################################################################
#	Store to stack
####################################################################################
	
	mtc1.d $a0, $f8 	# a0+a1 =  x_n
	mtc1.d $a2, $f10	# a2+a3 =  n

	mul.d $f12, $f8, $f8	# f12   =  pow(x_n, 2)
	sub.d $f12, $f12, $f10 	# f12   = (pow(x_n, 2) - n)
	add.d $f10, $f8, $f8 	# f14   = (2 * x_n)
	div.d $f10, $f12, $f10	# f14   = (pow(x_n, 2) - n) /(2 * x_n)
	sub.d $f10, $f8, $f10	# f14	=  x_n - ((x_n^2 - n) / (2 * x_n))
	
	mfc1.d $v0, $f10	#$v0 	=  x_n - ((x_n^2 - n) / (2 * x_n))

####################################################################################
#	Free stack
####################################################################################	
	l.d $f8, 0($sp)		# load f8 register
	l.d $f10, 8($sp)	# load f10 register
	l.d $f12, 16($sp)	# load f12 register
	
	addi $sp, $sp, 24
	add $sp, $sp, $t0
	
	jr $ra



####################################################################################
# Create a procedure that iteratively computest the square root of an input value
# n by using Newton's method.
####################################################################################
squareRoot:

####################################################################################
#	Store to stack
####################################################################################
	andi $t0, $sp, 7
	sub $sp, $sp, $t0
	addi $sp, $sp, -48
	
	s.d $f0, 0($sp)		# Save f0 register
	s.d $f2, 8($sp)		# Save f2 register
	s.d $f4, 16($sp)	# Save f4 register
	s.d $f6, 24($sp)	# Save f6 register
	s.d $f8, 32($sp)	# Save f8 register
	sw $ra, 40($sp)		# Save ra register
	sw $t0, 44($sp)		# Save t0 register
	
	mtc1.d $a0, $f0		# f0 = n 
	mtc1.d $a2, $f2		# f2 = limit
	
	li $t0, 1		# error = 1
	mtc1.d $t0, $f4
	cvt.d.w	$f4, $f4	# $f4 = error(double)

	mtc1.d $t0, $f6
	cvt.d.w	$f6, $f6	# $f6 = x_n(double)

loop:
	c.lt.d $f2, $f4		# if error <= limit jump to exit
	bc1f exit
	
	mfc1.d $a0, $f6		# a0 = x_n
	mfc1.d $a2, $f0		# a2 = n
	jal getNextSquareRootApprox
	
	mtc1.d $v0, $f8		#f8 = x_n_plus_one

	mfc1.d $a0, $f8	
	mfc1.d $a2, $f6
	jal computeError
	
	mtc1.d $v0, $f4		# return error
	mov.d $f6, $f8
	
	j loop
exit:
	mfc1.d $v0, $f6
	
####################################################################################
#	Free stack
####################################################################################
	
	l.d $f0, 0($sp)		# get f0 back just in case
	l.d $f2, 8($sp)		# get f2 back just in case
	l.d $f4, 16($sp)	# get f4 back just in case
	l.d $f6, 24($sp)	# get f6 back just in case
	l.d $f8, 32($sp)	# get f8 back just in case
	lw $ra, 40($sp)		# Save ra register
	lw $t0, 44($sp)		# Save t0 register
	
	add $sp, $sp, $t0
	addi $sp, $sp, 48
	jr $ra			# go to return address

####################################################################################
exitProgram:	# don't put any code after this label, and DO NOT DELETE THIS LABEL
####################################################################################
