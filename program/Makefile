COMPILER=gcc
CFLAGS= -Wall -g -lm -ansi -std=c99 -pedantic
OBJECTS= pivoting.c no_pivot.c answer.c determinant.c swap.c print_matrix.c print_b.c readin.c add.c gauss.c
EXE= gauss


all: $(OBJECTS)
	$(COMPILER) $(CFLAGS) $(INCLUDE) $(OBJECTS) -lm -o $(EXE)


clean:
	rm gauss
