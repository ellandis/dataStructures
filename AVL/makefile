OBJS = avlque.o avl.o avlmain.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all : avlmain #test-integer

#test-integer : $(OBJS)
#		gcc $(LOPTS) $(OBJS) -o test-integer

#datester: $(OBJS)
#		gcc $(LOPTS) $(OBJS) -o datester

avlmain: $(OBJS)
		gcc $(LOPTS) $(OBJS) -o avlmain

avl.o: avl.c avl.h avlque.h
		gcc $(OOPTS) avl.c 

avlque.o:  avlque.c avlque.h
		gcc $(OOPTS) avlque.c


#datester.o : datester.c avlque.h integer.h
#		gcc $(OOPTS) datester.c 

avlmain.o: avlmain.c avl.h avlque.h
		gcc $(OOPTS) avlmain.c


test : avlmain
		./avlmain

valgrind :  avlmain
		valgrind avlmain

clean	:
		find . -maxdepth 1 -type f -executable -exec rm {} +

		#rm -f $(OBJS) test-integer
