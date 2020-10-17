#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct stack
{
    int top;
    int capacity;
    int *array;
    int size;
};
Stack *Create_Stack()
{
    Stack *Brick = malloc(1 * sizeof(Stack));
    Brick->top = -1;
    Brick->size = 0;
    Brick->capacity = 10;
    Brick->array = malloc(Brick->capacity * sizeof(int));
    assert(Brick->array != NULL);
    return Brick;
}
int Is_Empty(Stack *Brick)
{
    return Brick->top == -1;
}
int Is_Full(Stack *Brick)
{
    return Brick->top == Brick->capacity - 1;
}
void Push(Stack *Brick, int value)
{
    if (Is_Full(Brick))
    {
        printf("Stack Full\n");
        return;
    }
    else
    {
        Brick->array[++Brick->top] = value;
        Brick->size++;
    }
}
int Pop(Stack *Brick)
{
    if(Is_Empty(Brick))
    {
        printf("Stack is Empty");
        return -1;
    }
    else
    {
        Brick->size--;
        return Brick->array[Brick->top--] ;
    }    
}
int StackSize(Stack *Brick)
{
    return Brick->size;
}
void Delete_Stack(Stack *Brick)
{
    if (Brick)
    {
        if (Brick->array)
        {
            free(Brick->array);
        }
        free(Brick);
    }
}
void Display(Stack *Brick)
{
    if(Is_Empty(Brick)){
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        int i = Brick->top;
        int s = StackSize(Brick);
        while (!Is_Empty(Brick))
        {
            printf("%d)\t %d\n", i, Brick->array[i] );
            i--;
        }
        printf("Size = %d\n", s);
    }
}