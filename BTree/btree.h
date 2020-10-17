#ifndef __BTREE_H__
#define __BTREE_H__
#include <stdio.h>


typedef struct BTree bt;

extern bt* Create_BTreenode();
//extern bt* Insert_Node(bt*,int);
extern void Insert_Node(bt**,int);
extern void Delete_Tree(bt*);
extern void Display_LevelOrder(bt*);
extern void Display_PreOrder(bt*);
extern void Display_InOrder(bt*);
extern void Display_PostOrder(bt*);
extern int Find_Node(bt*,int);
extern int Find_Max(bt*);
extern int Find_Height(bt*);
extern bt* Deepest_Node(bt*);
extern int Add(bt*);

#endif