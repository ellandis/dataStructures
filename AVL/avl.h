#ifndef __AVL_H__
#define __AVL_H__
#include <stdio.h>

typedef struct AVL avl;
extern avl* Create_Avlnode();
extern int Height(avl*);
extern avl* Insert_Node(avl*,avl*,int);
extern avl* Find_Max(avl*);
extern avl* Find_Min(avl*);
extern avl* Single_Rotate_Left(avl*);
extern avl* Single_Rotate_Right(avl*);
extern avl* Double_Rotate_Left(avl*);
extern avl* Double_Rotate_Right(avl*);
extern int max(int,int);
extern void Display_LevelOrder(avl*);

#endif