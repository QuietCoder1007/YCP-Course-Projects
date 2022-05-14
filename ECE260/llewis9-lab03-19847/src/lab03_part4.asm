# 
# Anything after a # is a comment
# Use comments to describe what each line of code does
#

.globl ece260_main intarray empty hello goodbye	# make these labels accessible from other files for testing

####################################################################################

.data				# define contents of memory in the .data section
	# insert your data values here (arrays, strings, variables, etc.)
	# indent your data values just as this comment is indented
	intarray: .word 0 1 3 5 7 11 13 17 19 23
	empty: .space 10
	hello: .asciiz "Hello World!"
	goodbye: .asciiz "Goodbye"
####################################################################################

.text				# all instructions go in the .text section
ece260_main:
	# insert your instructions here
	# indent your instructions just as this comment is indented
	# stylistically, this indentation will make more sense later
	la $t0, intarray
	la $t1, empty
	la $t2, hello
	la $t3, goodbye
	