
SHELL = /bin/sh
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
CUNIT = -lcunit
LDLIBS = -lm

docker:
	docker run -it -v "/Users/axeljeremy/Google Drive/CS-4900/QuadSolver/src":/src/ ubuntu:gcc

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

output: main.o quadFun.o validation.o main.h
	${CC} main.o quadFun.o validation.o -o output ${LDLIBS}

gene:
	${CC} -c ${CFLAGS} gennum.c ${LDLIBS}

geneo: gennum.o 
	${CC} gennum.o  -o gen ${LDLIBS}

runtest:
	./qsTest > test_suite_results.out

rungen:
	./gen

run:
	./output 1 < test1.in > out1.out

run2:
	./output 2 < test2.in > out2.out

run3:
	./output 3 < user_input.in > out_user_input.out

runall:
	./makeall.sh

.PHONY : clean
clean:
	rm *.o output qsTest

