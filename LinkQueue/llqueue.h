#ifndef __LLQUEUE_H__
#define __LLQUEUE_H__
#include <stdio.h>

typedef struct LLQueue lque;
typedef struct ListNode lnode;
extern lque* Create_Queue();
extern int Is_Empty(lque*);
extern void Enqueue(lque*,int);
extern int Dequeue(lque*);
extern void Delete_Que(lque*);
extern void Display_Que(lque*);

#endif