#ifndef __DQUEUE_H__
#define __DQUEUE_H__
#include <stdio.h>

typedef struct DQueue dque;
typedef struct BTree bt;
extern dque *Create_DQueue();
extern void Enqueue(dque*,bt*);
extern bt*  Dequeue(dque*);
extern int Que_Size(dque*);
extern int Is_Full(dque*);
extern int Is_Empty(dque*);
extern void Display_DQueue(dque*);
extern void Delete_DQueue(dque*);
extern bt* Front(dque*);
extern void Double_DQueue(dque*);
extern void Shrink_DQueue(dque*);

#endif