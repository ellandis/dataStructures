#include <stdio.h>
#include "dqueue.h"


int main(int argc, char *argv[])
{
    dque* fifo = Create_DQueue();
    Enqueue(fifo,1);
    Enqueue(fifo,2);
    Enqueue(fifo,3);
    Enqueue(fifo,4);
    Enqueue(fifo,5);
    Enqueue(fifo,6);

    

    Display_DQueue(fifo);
    Delete_DQueue(fifo);
    return 0;
}
