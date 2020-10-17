#ifndef __PQUE_H__
#define __PQUE_H__
#include <stdio.h>
//Priority queue implemented as a Binary Heap


typedef struct BHEAP bheap;
extern bheap* Create_Bheap();
extern void  Insert_Bheap(bheap**,int);
extern void Reheap_Up(bheap*,int);
extern void Reheap_Down(bheap*,int);
extern void Build_Heap(bheap**,int);
extern void Resize_Heap(bheap*);
extern void Heap_Sort(bheap**);
extern int Parent(bheap*,int);
extern int Left_Child(bheap*,int);
extern int Right_Child(bheap*,int);
extern int Delete_Max(bheap*);
extern int Get_Max(bheap*);
extern void Destroy_Bheap(bheap*);
extern int Find_Min_in_Maxheap(bheap*);
extern int Delete_index(bheap*,int);
extern int Delete_Min(bheap*);
extern int Get_Min(bheap*);
extern void Display_Bheap(bheap*);


#endif