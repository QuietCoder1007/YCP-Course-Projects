# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl ece260_main doSingles doDoubles exitProgram singles doubles	# make these labels accessible from other files for testing

####################################################################################

.data
	# insert your data values here (arrays for singles and doubles)
	singles: .float 1.4563, 2.4564, -4.2342, 65.334
	doubles: .double 1.4563, 2.4564, -4.2342, 65.334
	# indent your data values just as this comment is indented
	
####################################################################################
	
.text
ece260_main:
	# you probably don't need instructions in the ece260_main section
	# this label is primarily here to assist with the automated unit tests

doSingles:
	# insert your instructions here for computing single-precision floating point values
	# indent your instructions just as this comment is indented
	la $t0, singles

	li $t0, 0
	lwc1 $f0, singles($t0)
	addi $t0, $t0, 4
	
	lwc1 $f1, singles($t0)
	addi $t0, $t0, 4
	
	lwc1 $f2, singles($t0)
	addi $t0, $t0, 4
	
	lwc1 $f3, singles($t0)
	
	add.s $f4, $f0, $f1
	add.s $f5, $f1, $f2
	add.s $f6, $f2, $f3
	
	mfc1 $s0, $f4
	mfc1 $s1, $f5
	mfc1 $s2, $f6
	
####################################################################################

doDoubles:
	# insert your instructions here for computing double-precision floating point values
	# indent your instructions just as this comment is indented
	la $t0, doubles
	li $t0, 0
	li $t1, 0
	
	ldc1 $f8, doubles($t0)
	addi $t0, $t0, 8
	addi $t1, $t1, 8

	ldc1 $f10, doubles($t0)
	addi $t0, $t0, 8
	addi $t1, $t1, 8
	
	ldc1 $f12, doubles($t0)
	addi $t0, $t0, 8
	addi $t1, $t1, 8
	
	ldc1 $f14, doubles($t0)
	
	add.d $f24, $f8, $f10
	add.d $f26, $f10, $f12
	add.d $f28, $f12, $f14
	
	mfc1.d $t0, $f24
	mfc1.d $t2, $f26
	mfc1.d $t4, $f28
	
	
	

####################################################################################
exitProgram:	# don't put any code after this label, and DO NOT DELETE THIS LABEL
####################################################################################
