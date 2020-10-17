#include <stdio.h>
#include <stdlib.h>
#include "dqueue.h"

struct DQueue{
    int *array;
    int front,rear;
    int capacity;
};
dque *Create_DQueue(){
    dque *que = malloc(sizeof(dque));
    que->front = que->rear = -1;
    que->capacity = 5;
    que->array = malloc(que->capacity * sizeof(int));
    return que;
}
void Enqueue(dque* que, int data){
    if(!Is_Full(que)){
        Double_DQueue(que);
    }
    que->rear = (que->rear + 1) % que->capacity;
    que->array[que->rear] = data;
    if(que->front == -1){
        que->front = que->rear;
    }
}
int Dequeue(dque* que){
    int data = 0;
    if(Is_Empty(que)){
        printf("Que is Empty\n");
    }
    else{
        data = que->array[que->front];
        if(que->front == que->rear){
            que->front = que->rear = -1; 
        }
        else{
            que->front = (que->front + 1) % que->capacity;
        }
    }
    return data;
}
int Is_Full(dque* que){
    return ((que->rear + 1) % que->capacity == que->front); 
    //return que->rear == que->capacity - 1;
}
int Is_Empty(dque* que){
    return que->front == -1;
}
int Que_Size(dque* que){
    return (que->capacity - que->front + que->rear + 1) % que->capacity;
}
void Double_DQueue(dque* que){
    int size = que->capacity;
    que->capacity = que->capacity * 2;
    que->array = realloc(que->array,que->capacity);
    if(!que->array){
        printf("Memory Error\n");
        return;
    }
    if(que->front > que->rear){
        for (int i = 0; i < que->front; i++)
        {
            que->array[i+size] = que->array[i];
        }
        que->rear += size;
    }
    //printf("que Doubled\n");
    //que->capacity *= 2;
    //que->array = realloc(que->array, que->capacity * sizeof(int));
}
void Shrink_DQueue(dque* que){
    que->capacity /= 2;
    if(que->capacity < 4){
        que->capacity = 4;
    }
    que->array = realloc(que->array, que->capacity * sizeof(int));
}
void Delete_DQueue(dque* que){
    if(que){
        if(que->array){
            free(que->array);
        }
        free(que);
        printf("Que is Destroyed\n");
    }
}
void Display_DQueue(dque* que){
    int k = 0;
    int i = que->front;
    if (Is_Empty(que))
    {
        printf("Que is Empty\n");
    }
    else{
        while(k < Que_Size(que)){
            printf("[%d]-%d\n",i,que->array[i]);
            i = (i + 1) % que->capacity;
            k++;
        }
    }
}
int Front(dque* que){
    return que->array[que->front];
}