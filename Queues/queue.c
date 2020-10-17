#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

struct Queue{
    int front,rear;
    int *array;
    int capacity;
};
que* Create_Queue(){
    que* line = malloc(sizeof(que));
    assert(line != NULL);
    line->front = line->rear = -1;
    line->capacity = 5;
    line->array = malloc(line->capacity * sizeof(int));
    return line;
}
void Enqueue(que* line, int data){
    if (Is_Full(line)){
        printf("Que is Full\n");
        
    }
    else{
        line->rear = (line->rear + 1) % line->capacity;
        line->array[line->rear] = data;
        if (line->front == -1)
        {
            line->front = line->rear;
        }
    }
}
int Dequeue(que* line){
    int data = 0;
    if(Is_Empty(line)){
        printf("Empty Queue\n");
        return 0;
    }
    else{
        data = line->array[line->front];
        if (line->front == line->rear)
        {
            line->front = line->rear = -1;
        }
        else{
            line->front = (line->front + 1) % line->capacity;
        }
    }
    return data;
}
int Is_Full(que* line){
    return ((line->rear + 1) % line->capacity == line->front);
}
int Is_Empty(que* line){
    return line->front == -1;
}
int Que_Size(que* line){
    return (line->capacity - line->front + line->rear + 1) % line->capacity;
}
void Delete_Que(que* line){
    if (line)
    {
        if (line->array)
        {
            free(line->array);
        }
        free(line);   
    }
}
int Front(que* line){
    return line->array[line->front];
}
void Display_Que(que* line){
    int k = 0 ;
    int i = line->front;
    if (Is_Empty(line))
    {
        printf("Empty Que\n");
    }
    else {
        while (k < Que_Size(line))
        {
            printf("[%d]- %d\n",i, line->array[i]);
            i = (i + 1) % line->capacity;
            k++;
        }
    }
}