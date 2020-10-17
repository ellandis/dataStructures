#include "avlque.h"
#include "stdio.h"
#include "stdlib.h"

struct AVL{
    int data;
    avl* left;
    avl* right;
};
struct AvlQue
{
    int front,rear,capacity;
    avl** array;
};
avlque* Create_AvlQue(){
    avlque* que = malloc(sizeof(avlque));
    que->front = que->rear = -1;
    que->capacity = 5;
    que->array = malloc(que->capacity * sizeof(avl*));
    return que;
}
void Enqueue(avlque* que, avl* data){
    if(!Is_Full(que)){
        Double_AvlQue(que);
    }
    que->rear = (que->rear + 1) % que->capacity;
    que->array[que->rear] = data;
    if(que->front == -1){
        que->front = que->rear;
    }
}
avl* Dequeue(avlque* que){
    avl* data;
    if(Is_Empty(que)){
        printf("Que is Empty\n");
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
int Is_Full(avlque* que){
    return ((que->rear + 1) % que->capacity == que->front);
}
int Is_Empty(avlque* que){
    return que->front == -1;
}
int Que_Size(avlque* que){
    return (que->capacity - que->front + que->rear + 1) % que->capacity;
}
void Double_AvlQue(avlque* que){
    que->capacity *= 2;
    que->array = realloc(que->array, que->capacity * sizeof(avl*));
}
void Shrink_AvlQue(avlque* que){
    que->capacity /= 2;
    if(que->capacity < 5){
        que->capacity = 5;
    }
    que->array = realloc(que->array, que->capacity * sizeof(avl*));    
}
void Delete_AvlQue(avlque* que){
    if(que){
        if(que->array){
            free(que->array);
        }
        free(que);
    }
}
void Display_AvlQue(avlque* que){
    int k=0;
    int i = que->front;
    avl* node;
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
avl* Front(avlque* que){
    return que->array[que->front];
}
