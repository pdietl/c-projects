
eat:	eat.o io.o logic.o scanner.o
	gcc -g -Wall -Wextra -o eat eat.o io.o logic.o scanner.o -lm

eat.o:	eat.c io.h scanner.h logic.h
	gcc -g -Wall -Wextra -c eat.c

io.o:	io.h scanner.h io.c
	gcc -g -Wall -Wextra -c io.c

logic.o:	logic.h logic.c
	gcc -g -Wall -Wextra -c logic.c

scanner.o:	scanner.c scanner.h
	gcc -g -Wall -Wextra -c scanner.c

clean:
	rm -f *.o eat eat.exe

test:	eat
	cat test.dat | eat
