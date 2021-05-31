# build an executable named assignment3 from assignment3.c
all: assignment3.c
	 gcc assignment3.c -o assignment3

clean:
	 $(RM) assignment3

run:
	$ ./assignment3
