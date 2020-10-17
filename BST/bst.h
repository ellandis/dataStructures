#ifndef __BST__H__
#define __BST__H__
#include <stdio.h>

typedef struct BST bst;
extern bst* Create_BSTreeNode();
extern void Insert_Node(bst**,int);
extern bst* Find_Max(bst*);
extern bst* Find_Min(bst*);
extern bst* Find_Kth(bst*,int,int);
extern bst* Find_Node(bst*,int);
extern void Sort_BSTree(bst*);
extern void Display_LevelOrder(bst*);
extern bst* Delete_Node(bst*,int);

#endif