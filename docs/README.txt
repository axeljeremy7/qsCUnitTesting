Compiling:
	
	To compile qSolver.c, use:
		gcc -std=c99 -o qSolver qSolver.c -lm
	
	-lm is needed or else gcc will not recognize the math library

	This creates an executable file to use for our quad solver.

Running:

	To run the executable made above, use:
		./qSolver <value a> <value b> <value c>

	This program is designed to take arguments from cmd as input. If arguments are not given, the user will be prompted to input them.
