
SHELL = /bin/sh
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
CUNIT = -lcunit
LDLIBS = -lm

docker:
	docker run -it -v "/Users/axeljeremy/Google Drive/CS-4900/QuadSolver/":/QuadSolver/ ubuntu:gcc

main.o: main.h
	${CC} -c ${CFLAGS} main.c ${LDLIBS}

quadFun.o: header.h quadFun.h
	${CC} -c ${CFLAGS} quadFun.c ${LDLIBS}

validation.o: header.h validation.h
	${CC} -c ${CFLAGS} validation.c ${LDLIBS}

test.o: variables.h header.h validation.h quadFun.h test.h
	${CC} -c ${CFLAGS} test.c ${LDLIBS} ${CUNIT}

test: test.o quadFun.o validation.o
	${CC} test.o quadFun.o validation.o -o qsTest ${LDLIBS} ${CUNIT}

qSolver: main.o quadFun.o validation.o main.h
	${CC} main.o quadFun.o validation.o -o qSolver ${LDLIBS}

gene:
	${CC} -c ${CFLAGS} gennum.c ${LDLIBS}

geneo: gennum.o 
	${CC} gennum.o  -o gen ${LDLIBS}

run:
	./qSolver 1 < input/val1.in > output/val1.out 2> logs/error.txt

run2:
	./qSolver 2 < input/val2.in > output/val2.out 2> logs/error.txt

user:
	./qSolver 3 < input/user_input.in > output/user_output.out 2> logs/error.txt

runtest:
	./qsTest > output/test_suite.results 2> logs/error.txt

rungen:
	./gen

userrun:
	./runuser.sh

allrun:
	./makeall.sh

.PHONY : clean
clean:
	rm *.o qSolver qsTest

