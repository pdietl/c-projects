image:	image.o ppm.o scanner.o
	gcc -g -Wall -Wextra -o image image.o ppm.o scanner.o -lm

image.o:	image.c scanner.h ppm.h
	gcc -g -Wall -Wextra -c image.c

ppm.o:	ppm.c ppm.h
	gcc -g -Wall -Wextra -c ppm.c

scanner.o:	scanner.c scanner.h
	gcc -g -Wall -Wextra -c scanner.c

clean:
	rm -f *.o image.exe image

