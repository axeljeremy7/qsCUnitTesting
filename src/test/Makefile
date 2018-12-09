SHELL = /bin/sh
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
LDLIBS = -lm


validation.o: ../include/header.h ../include/validation.h ../validation.c
	${CC} -c ${CFLAGS} ../validation.c ${LDLIBS}

testvalidation.o: testvalidation.c
	${CC} -c ${CFLAGS} testvalidation.c ${LDLIBS}	

testvalidation: testvalidation.o validation.o
	${CC} testvalidation.o validation.o -o testvalidation ${LDLIBS}

run1:
	./testvalidation 2> ../logs/test1_logs.txt

runall1:
	./t1.sh	

cunit.o: ../include/cunit.h
	${CC} -c ${CFLAGS} cunit.c ${LDLIBS}	

quadFun.o: ../include/header.h ../include/quadFun.h 
	${CC} -c ${CFLAGS} ../quadFun.c ${LDLIBS}	

testroots.o: ../include/cunit.h
	${CC} -c ${CFLAGS} testroots.c ${LDLIBS}

testroots: testroots.o quadFun.o cunit.o
	${CC} testroots.o quadFun.o cunit.o -o testroots ${LDLIBS}

run2:
	./testroots 2> ../logs/test2_logs.txt

runall2:
	./t2.sh	

systemtest:
	.././newmain < test1.in 2> ../logs/test1.out

.PHONY : clean
clean:
	rm -f *.o testvalidation testroots
