#ifndef __DSTACK_H__
#define __DSTACK_H__
#include<stdio.h>

typedef struct dstack DStack;

extern DStack* Create_DStack();
extern void Push(DStack*,int);
extern int Pop(DStack*);
extern int Is_Empty(DStack*);
extern int Is_Full(DStack*);
extern int Stack_Size(DStack*);
extern void Delete_Stack(DStack*);
extern void Display_Stack(DStack*);
extern void Double_Capacity(DStack*);
extern void Shrink_Capacity(DStack*);

#endif 
