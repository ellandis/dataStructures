#include <stdio.h>
#include <stdlib.h>
#include "llqueue.h"


struct ListNode{
    int data;
    lnode* next;
};
struct LLQueue{
    lnode *front;
    lnode *rear;
    int size;
};
lque* Create_Queue(){
    lque* q = malloc(sizeof(lque));
    if(!q)
        return NULL;
    lnode* temp = malloc(sizeof(lnode));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}
int Is_Empty(lque* q){
    return q->front == NULL;
}
void Enqueue(lque* q, int data){
    lnode* newNode = malloc(sizeof(lnode));
    //if(!newNode)
    //    return -1;
    newNode->data = data;
    newNode->next = NULL;
    if(q->rear){
        q->rear->next = newNode;
    }
    q->rear = newNode;
    if(q->front == NULL){
        q->front = q->rear;
    }
    q->size++;
}
int Dequeue(lque* q){
    lnode* temp;
    int data = 0;
    if(Is_Empty(q)){
        printf("Empty Que");
    }
    else{
        temp = q->front;
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }
    q->size--;
    return data;
}
void Delete_Que(lque* q){
    lnode* temp;
    while(q){
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
    printf("Que is Destroyed\n");
}
void Display_Que(lque* q){
    int k = 0;
    lque* j = q;
    if(Is_Empty(q)){
        printf("Queue is Empty\n");
    }
    else
    {
        while(k < q->size){
            printf("[%d] - %d\n",k,j->front->data);
            j->front = j->front->next;
            k++;
        }
    }
    
}