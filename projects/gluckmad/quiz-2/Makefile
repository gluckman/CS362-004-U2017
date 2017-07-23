CFLAGS = -Wall -lm

testme: testme.c
	gcc -o testme -g testme.c $(CFLAGS)
	./testme

all: testme

clean:
	rm -f *.o testme *.so *.out
