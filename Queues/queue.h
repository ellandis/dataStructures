#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdio.h>


typedef struct Queue que;
extern que* Create_Queue();
extern void Enqueue(que*, int);
extern int Dequeue(que*);
extern int Que_Size(que*);
extern int Is_Full(que*);
extern int Is_Empty(que*);
extern void Display_Que(que*);
extern void Delete_Que(que*);
extern int Front(que*);





#endif