/*
    THIS QUEUE IS FOR BTREE NODES
    btree.h btree.c btmain.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "dqueue.h"

struct BTree{
    int data;
    bt *left;
    bt *right;
};
struct DQueue{
    bt **array;
    int front,rear;
    int capacity;
};
dque *Create_DQueue(){
    dque *que = malloc(sizeof(dque));
    que->front = que->rear = -1;
    que->capacity = 4;
    que->array = malloc(que->capacity * sizeof(bt*));
    return que;
}
void Enqueue(dque* que, bt* data){
    if(!Is_Full(que)){
        Double_DQueue(que);
    }
    que->rear = (que->rear + 1) % que->capacity;
    que->array[que->rear] = data;
    if(que->front == -1){
        que->front = que->rear;
    }
}
bt* Dequeue(dque* que){
    bt* data;
    if(Is_Empty(que)){
        printf("Que is Empty");
        return 0;
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
}
int Is_Empty(dque* que){
    return que->front == -1;
}
int Que_Size(dque* que){
    return (que->capacity - que->front + que->rear + 1) % que->capacity;
}
void Double_DQueue(dque* que){
    /*int size = que->capacity;
    que->capacity = que->capacity * 2;
    que->array = realloc(que->array,1 * que->capacity);
    if(!que->array){
        printf("Memory Error\n");
        return;
    }
    if(que->front > que->rear){
        for (int i = 0; i < que->front; i++)
        {
            que->array[i+size] = que->array[i];
        }
        que->rear = que->rear + size;
    }*/
    que->capacity *= 2;
    que->array = realloc(que->array, que->capacity * sizeof(int));
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
        //printf("Que is Destroyed\n");
    }
}
void Display_DQueue(dque* que){
    int k = 0;
    int i = que->front;
    bt* node;
    if (Is_Empty(que))
    {
        printf("Que is Empty\n");
    }
    else{
        while(k < Que_Size(que)){
            node = que->array[i];
            printf("[%d]-%d\n",i,node->data);
            i = (i + 1) % que->capacity;
            k++;
        }
    }
}
bt* Front(dque* que){
    return que->array[que->front];
}