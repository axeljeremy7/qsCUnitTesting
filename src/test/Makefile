SHELL = /bin/sh
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
LDLIBS = -lm


validation.o: ../include/header.h ../include/validation.h
	${CC} -c ${CFLAGS} validation.c ${LDLIBS}

testvalidation.o: 
	${CC} -c ${CFLAGS} testvalidation.c ${LDLIBS}	

testvalidation: testvalidation.o validation.o
	${CC} testvalidation.o validation.o -o testvalidation ${LDLIBS}

run1:
	./testvalidation 2> ../logs/test1_logs.txt

runall1:
	./t1.sh	
	

quadFun.o: ../include/header.h ../include/quadFun.h
	${CC} -c ${CFLAGS} quadFun.c ${LDLIBS}	

testroots.o:
	${CC} -c ${CFLAGS} testroots.c ${LDLIBS}

testroots: testroots.o quadFun.o
	${CC} testroots.o quadFun.o -o testroots ${LDLIBS}

run2:
	./testroots 2> ../logs/test2_logs.txt

runall2:
	./t2.sh	

.PHONY : clean
clean:
	rm -f *.o testvalidation testroots
