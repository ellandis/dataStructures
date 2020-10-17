#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "dynA.h"

struct da{
    int size;
    int capacity;
    int *house;
    int debug;
};
DA *Create_DA(){
    DA *foundation = malloc(1 * sizeof(DA));
    foundation->capacity = 1;
    foundation->size = 0;
    foundation->debug = 1;
    foundation->house = malloc(foundation->capacity * sizeof(int));
    return foundation;
}
void Display_DA(DA** dynarr){
    int i = 0,j=0;
    if((*dynarr)->debug == 1){
        while (i < (*dynarr)->size){
            printf("[%d]-- %d\n", i,(*dynarr)->house[i]);
            i++;
        }
        printf("\n");
    }
    else{
        while (i < (*dynarr)->size){
            printf("[%d] %d\n", i,(*dynarr)->house[i]);
            i++;
        }
    }   
}
void Double_Capacity(DA* dynarr){
    dynarr->capacity *= 2;
    dynarr->house = realloc(dynarr->house, sizeof(DA*) * dynarr->capacity);
    printf("Capacity is %d\n",dynarr->capacity);
}
void Shrink_Capacity(DA* dynarr){
    dynarr->capacity /= 2;
    dynarr->house = realloc(dynarr->house, sizeof(DA*) * dynarr->capacity);
    printf("Capacity is %d\n",dynarr->capacity);
}
int Get_Size(DA* dynarr){
    return dynarr->size;
}
int Get_Capacity(DA* dynarr){
    return dynarr->capacity;
} 
void Insert_Item_Front(DA* dynarr,int value){
    int i=0, j = dynarr->size;
    if(dynarr->size == 0){
        dynarr->house[dynarr->size] = value;
    }
    else{
        if(dynarr->size == dynarr->capacity)
            Double_Capacity(dynarr);
        while (j >= 0){
            dynarr->house[j+1] = dynarr->house[j];
            j--;
        }
        dynarr->house[i] = value;
    }
    dynarr->size++;
}
void Insert_Item_Back(DA* dynarr, int value){
    if(dynarr->size == dynarr->capacity){
        Double_Capacity(dynarr);
    }
    dynarr->house[dynarr->size]  = value;
    dynarr->size += 1;
}
void Insert_Item_Pos(DA* dynarr, int pos, int value){
    if(dynarr->size == dynarr->capacity)
            Double_Capacity(dynarr);
    if (pos > dynarr->size){
        perror("OUT OF RANGE SIZE TO LARGE");
        return;
    }
    if (pos == 0){
        Insert_Item_Front(dynarr,value);
    }
    else if (pos <= dynarr->size){
        int i = dynarr->size;
        while (i >= pos)
        {
            dynarr->house[i+1] = dynarr->house[i];
            i--; 
        }
        dynarr->house[pos] = value;
    }
    dynarr->size++;
}
void Delete_Item_Front(DA* dynarr){
    int i = 0;
    while (i < dynarr->size){
        dynarr->house[i] = dynarr->house[i+1];
        i++;
    }
    dynarr->size--;
    if(dynarr->size < (dynarr->capacity / 2)){
        Shrink_Capacity(dynarr);
    }
}
void Delete_Item_Back(DA* dynarr){
    dynarr->house[dynarr->size] = '\0';
    dynarr->size--;
    if(dynarr->size < (dynarr->capacity / 2)){
        Shrink_Capacity(dynarr);
    }
}
void Delete_Item_Pos(DA* dynarr,int pos,int value){
    int i = pos;
    dynarr->house[i] = '\0';
    while (i < dynarr->size)
    {
        dynarr->house[i] = dynarr->house[i+1];
        i++;
    }
    dynarr->size--;
    if(dynarr->size < (dynarr->capacity / 2)){
        Shrink_Capacity(dynarr);
    }
}
void Sort(DA* dynarr){
    Quick_Sort(dynarr->house,0,dynarr->size);
}
void Quick_Sort(int* dynarr, int low, int high){
    int pivot;
    if(high > low){
        pivot = Partition(dynarr,low,high);
        Quick_Sort(dynarr, low, pivot-1);
        Quick_Sort(dynarr, pivot+1, high);
    }
}
int Partition(int* dynarr, int low, int high){
    int left,right, pivot_item = dynarr[low], temp;
    left = low;
    right = high;
    while(left < right){
        //move left while item < pivot
        while(dynarr[left] <= pivot_item)
            left++;
        //move right while item > pivot
        while(dynarr[right] > pivot_item)
            right--;
        if(left < right){
            temp = dynarr[left];
            dynarr[left] = dynarr[right];
            dynarr[right] = temp;
        }
    }
    //right is final position for the pivot
    dynarr[low] = dynarr[right];
    dynarr[right] = pivot_item;
    return right;
}
void Free_DA(DA* dynarr){
    free(dynarr);
    printf("Free\n");
    return;
}