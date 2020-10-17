#ifndef __BSTQUE_H__
#define __BSTQUE_H__
#include <stdio.h>

typedef struct BstQue bstque;
typedef struct BST bst;
extern bstque *Create_BstQue();
extern void Enqueue(bstque*,bst*);
extern bst*  Dequeue(bstque*);
extern int Que_Size(bstque*);
extern int Is_Full(bstque*);
extern int Is_Empty(bstque*);
extern void Display_BstQue(bstque*);
extern void Delete_BstQue(bstque*);
extern bst* Front(bstque*);
extern void Double_BstQue(bstque*);
extern void Shrink_BstQue(bstque*);


#endif