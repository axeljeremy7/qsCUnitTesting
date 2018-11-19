
SHELL = /bin/sh
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
LDLIBS = -lm

docker:
	docker run -it -v "/Users/axeljeremy/Google Drive/CS-4900/QuadSolver/src":/src/ ubuntu:gcc

main.o: main.h
	${CC} -c ${CFLAGS} main.c ${LDLIBS}

quadFun.o: header.h quadFun.h
	${CC} -c ${CFLAGS} quadFun.c ${LDLIBS}

validation.o: header.h validation.h
	${CC} -c ${CFLAGS} validation.c ${LDLIBS}

output: main.o quadFun.o validation.o main.h
	${CC} main.o quadFun.o validation.o -o output ${LDLIBS}

gene:
	${CC} -c ${CFLAGS} gennum.c ${LDLIBS}

geneo: gennum.o 
	${CC} gennum.o  -o gen ${LDLIBS}

rungen:
	./gen

run:
	./output < test1.in

run2:
	./output < test2.in

.PHONY : clean
clean:
	rm *.o output

