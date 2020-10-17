#ifndef __DYNA_H__
#define __DYNA_H__

typedef struct da DA;

extern DA *Create_DA();
extern void Display_DA(DA**);
extern int Get_Size(DA*);
extern int Get_Capacity(DA*);

extern void Insert_Item_Front(DA*,int);
extern void Insert_Item_Back(DA*,int);
extern void Insert_Item_Pos(DA*,int,int);

extern void Delete_Item_Front(DA*);
extern void Delete_Item_Back(DA*);
extern void Delete_Item_Pos(DA*,int,int);

extern void Sort(DA*);
extern void Quick_Sort(int[],int,int);
extern int Partition(int[],int,int);
extern void Double_Capacity(DA*);
extern void Shrink_Capacity(DA*);
extern void Free_DA(DA*);

#endif