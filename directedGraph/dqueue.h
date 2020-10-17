#ifndef __DQUEUE_H__
#define __DQUEUE_H__
#include <stdio.h>

typedef struct DQueue dque;
extern dque *Create_DQueue();
extern void Enqueue(dque*,int);
extern int Dequeue(dque*);
extern int Que_Size(dque*);
extern int Is_Full(dque*);
extern int Is_Empty(dque*);
extern void Display_DQueue(dque*);
extern void Delete_DQueue(dque*);
extern int Front(dque*);
extern void Double_DQueue(dque*);
extern void Shrink_DQueue(dque*);

#endif