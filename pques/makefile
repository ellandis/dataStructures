OBJS = pque.o pquemain.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all : pquemain #test-integer

#test-integer : $(OBJS)
#		gcc $(LOPTS) $(OBJS) -o test-integer

#datester: $(OBJS)
#		gcc $(LOPTS) $(OBJS) -o datester

pquemain: $(OBJS)
		gcc $(LOPTS) $(OBJS) -o pquemain

#pque.o: pque.c pque.h
#		gcc $(OOPTS) pque.h

pque.o: pque.c pque.h
		gcc $(OOPTS) pque.c 

#datester.o : datester.c pque.h integer.h
#		gcc $(OOPTS) datester.c 

pquemain.o: pquemain.c pque.h
		gcc $(OOPTS) pquemain.c

test : pquemain
		./pquemain

valgrind :  pquemain
		valgrind pquemain

clean	:
		find . -maxdepth 1 -type f -executable -exec rm {} +

		#rm -f $(OBJS) test-integer
