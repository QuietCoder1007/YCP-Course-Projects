# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl ece260_main eq1_computation eq2_computation exitProgram eq1_vals eq2_vals # make these labels accessible from other files for testing

####################################################################################

.data
	# insert your data values here (arrays for singles and doubles)
	# indent your data values just as this comment is indented
	eq1_vals: .float 25.9, 3.14159265359
	eq2_vals: .double -44.321, 9.12, 2.53, 1.25
	
####################################################################################

.text
ece260_main:
	# you probably don't need instructions in the ece260_main section
	# this label is primarily here to assist with the automated unit tests

eq1_computation:
	# insert your instructions here for computing single-precision floating point values
	# indent your instructions just as this comment is indented
	la $t0, eq1_vals
	li $t0, 0
	
	lwc1 $f0, eq1_vals($t0) 	# $f0 = r
	addi $t0, $t0, 4
	
	lwc1 $f1, eq1_vals($t0)		# $f1 =  pi
	addi $t0, $t0, 4	
	
	mul.s $f2, $f0, $f0 		# $f0 = r^2
	mul.s $f3, $f2, $f1		# $f3 = r^2 * pi
	
	mfc1 $s0, $f3
####################################################################################
		
eq2_computation:
	# insert your instructions here for computing double-precision floating point values
	# indent your instructions just as this comment is indented
	la $t0, eq2_vals
	li $t0, 0
	li $t1, 0
	
	ldc1 $f10, eq2_vals($t0)	# $f10 = x
	addi $t0, $t0, 8
	addi $t1, $t1, 8
	
	ldc1 $f12, eq2_vals($t0)	# $f12 =  y
	addi $t0, $t0, 8
	addi $t1, $t1, 8
	
	ldc1 $f14, eq2_vals($t0)	# $f14 = 2.53
	addi $t0, $t0, 8
	addi $t1, $t1, 8
	
	ldc1 $f16, eq2_vals($t0)	# $f16 = 1.25
	addi $t0, $t0, 8
	addi $t1, $t1, 8
	
	mul.d $f10, $f10, $f10 		# $f10 = x^2
	mul.d $f10, $f14, $f10 		# $f4 = 2.53 * x^2
	
	div.d $f12, $f16, $f12		# $f6 = 1.25 / y
	
	add.d $f28, $f10, $f12		# $f28 = (2.53 * x^2) + (1.25 / y)
	
	mfc1.d $t0, $f28
	
####################################################################################
exitProgram:	# don't put any code after this label, and DO NOT DELETE THIS LABEL
####################################################################################
