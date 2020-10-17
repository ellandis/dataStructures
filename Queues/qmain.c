#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[])
{
    que* line = Create_Queue();
    //Display_Que(line);
    Enqueue(line,1);
    Enqueue(line,2);
    Enqueue(line,3);
    Enqueue(line,4);
    Enqueue(line,5);
    //Display_Que(line);
    Dequeue(line);
    Dequeue(line);
    printf("\n");
    Enqueue(line,6);
    Enqueue(line,7);
    Display_Que(line);
    return 0;
}
