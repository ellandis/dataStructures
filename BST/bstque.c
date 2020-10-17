/*
    THIS QUEUE IS FOR BSTREE NODES
    bst.c bst.h bstmain.c
*/
#include "bstque.h"
#include "stdio.h"
#include "stdlib.h"

struct BST{
    int data;
    bst* left;
    bst* right;
};
struct BstQue
{
    int front,rear,capacity;
    bst** array;
};
bstque* Create_BstQue(){
    bstque* que = malloc(sizeof(bstque));
    que->front = que->rear = -1;
    que->capacity = 5;
    que->array = malloc(que->capacity * sizeof(bst*));
    return que;
}
void Enqueue(bstque* que, bst* data){
    if(!Is_Full(que)){
        Double_BstQue(que);
    }
    que->rear = (que->rear + 1) % que->capacity;
    que->array[que->rear] = data;
    if(que->front == -1){
        que->front = que->rear;
    }
}
bst* Dequeue(bstque* que){
    bst* data;
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
int Is_Full(bstque* que){
    return ((que->rear + 1) % que->capacity == que->front);
}
int Is_Empty(bstque* que){
    return que->front == -1;
}
int Que_Size(bstque* que){
    return (que->capacity - que->front + que->rear + 1) % que->capacity;
}
void Double_BstQue(bstque* que){
    que->capacity *= 2;
    que->array = realloc(que->array, que->capacity * sizeof(bst*));
}
void Shrink_BstQue(bstque* que){
    que->capacity /= 2;
    if(que->capacity < 5){
        que->capacity = 5;
    }
    que->array = realloc(que->array, que->capacity * sizeof(bst*));    
}
void Delete_BstQue(bstque* que){
    if(que){
        if(que->array){
            free(que->array);
        }
        free(que);
    }
}
void Display_BstQue(bstque* que){
    int k=0;
    int i = que->front;
    bst* node;
    if(Is_Empty(que)){
        printf("Que si Empty");
    }
    else{
        while(k < Que_Size(que)){
            node = que->array[i];
            printf("[%d] - %d\n", i, node->data);
            i = (i + 1) % que->capacity;
            k++;
        }
    }
}
bst* Front(bstque* que){
    return que->array[que->front];
}
