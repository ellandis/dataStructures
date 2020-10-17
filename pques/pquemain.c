#include<stdio.h>
#include<stdlib.h>
#include "pque.h"

int main(int argc, char* argv[]){
    bheap* heap = Create_Bheap();
    int num = 0,i=0;

    FILE *fp = fopen(argv[1],"r");
    if(argc < 2){
        perror("Missing File:");
    }
    fscanf(fp,"%d",&num);
    while(!feof(fp)){
        Insert_Bheap(&heap,num);
        //Build_Heap(&heap,num);
        fscanf(fp,"%d",&num);
        i++;
    }
    Display_Bheap(heap);
    Heap_Sort(&heap);
    Display_Bheap(heap);
    Delete_Max(heap);
    int y = Find_Min_in_Maxheap(heap);
    printf("smallest in the heap is: %d\n",y);
    Display_Bheap(heap);
    printf("%d\n",Get_Max(heap));
    Destroy_Bheap(heap);

    //Display_LevelOrder(heap);
    return 0;
}