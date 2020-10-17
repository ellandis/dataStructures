#include <stdio.h>
#include "llqueue.h"

int main(int argc, char *argv[])
{
    lque* que = Create_Queue();
    Display_Que(que);
    Enqueue(que,1);
    Enqueue(que,2);
    Enqueue(que,3);
    Enqueue(que,4);
    Dequeue(que);
    Dequeue(que);
    Dequeue(que);
    Display_Que(que);

    return 0;
}
