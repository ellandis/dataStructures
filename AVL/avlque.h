#ifndef __AVLQUE_H__
#define __AVLQUE_H__
#include <stdio.h>

typedef struct AvlQue avlque;
typedef struct AVL avl;
extern avlque *Create_AvlQue();
extern void Enqueue(avlque*,avl*);
extern avl*  Dequeue(avlque*);
extern int Que_Size(avlque*);
extern int Is_Full(avlque*);
extern int Is_Empty(avlque*);
extern void Display_AvlQue(avlque*);
extern void Delete_AvlQue(avlque*);
extern avl* Front(avlque*);
extern void Double_AvlQue(avlque*);
extern void Shrink_AvlQue(avlque*);


#endif