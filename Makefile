# Makefile for OPS excercise 2
# Use tabs for indentation, not spaces!

# Link object files and create a binary executable:
display: display.o displayFunctions.o testFunctions.o
	gcc -Wall -o display display.o displayFunctions.o testFunctions.o

# Compile C-files and create object files (.o).
# The option -c ensures no linking takes place:
display.o: display.c displayFunctions.h errorCode.h
	gcc -c -Wall display.c

displayFunctions.o: displayFunctions.c displayFunctions.h testFunctions.h errorCode.h
	gcc -c -Wall displayFunctions.c

testFunctions.o: testFunctions.c testFunctions.h errorCode.h
	gcc -c -Wall testFunctions.c

clean:
	rm -f *.o

cleanall: clean
	rm -f display

