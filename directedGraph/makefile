OBJS = dqueue.o graph.o graphmain.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all : graphmain

graphmain: $(OBJS)
		gcc $(LOPTS) $(OBJS) -o graphmain

dqueue.o: dqueue.c dqueue.h
		gcc $(OOPTS) dqueue.c

graph.o: graph.c graph.h
		gcc $(OOPTS) graph.c 

graphmain.o: graphmain.c graph.h dqueue.h
		gcc $(OOPTS) graphmain.c

test : graphmain
		./graphmain

valgrind :  graphmain
		valgrind graphmain

clean	:
		find . -maxdepth 1 -type f -executable -exec rm {} +

		#rm -f $(OBJS) test-integer
