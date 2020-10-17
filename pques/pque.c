#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pque.h"
//Priority queue implemented as a Binary Heap

struct BHEAP{
    int *array;
    int count;
    int capacity;
};
bheap* Create_Bheap(){
    bheap* heap = malloc(sizeof(bheap));
    assert(heap != NULL);
    heap->count = 0;
    heap->capacity = 1;
    heap->array = malloc( sizeof(int) * heap->capacity);
    assert(heap->array != NULL);
    return heap;
}
void Insert_Bheap(bheap** heap,int data){
    //multiple ways to build a heap
    Reheap_Up((*heap),data);
    //Second way put all items in array then heapsort
    /*if((*heap)->count == (*heap)->capacity){
        Resize_Heap((*heap));
    }
    (*heap)->array[(*heap)->count] = data;
    (*heap)->count++;*/
}
void Build_Heap(bheap** heap,int data){
    if((*heap) == NULL){
        return;
    }
    Reheap_Up((*heap),data);
}
void Reheap_Up(bheap* heap, int data){
    int i;
    if(heap->count == heap->capacity){
        Resize_Heap(heap);
    }
    heap->count++;
    i = heap->count-1;
    while(i>0 && data > heap->array[(i-1)/2]){
        heap->array[i] = heap->array[(i-1)/2];
        i = (i-1)/2;
    }
    heap->array[i] = data;  
}
void Reheap_Down(bheap* heap,int index){
    int left,right,max,temp;
    left = Left_Child(heap,index);
    right = Right_Child(heap,index);
    max = index;
    if(left != -1){
        if(heap->array[left] > heap->array[index]){
            max = left;
        }
    }
    else{
        max = index;
    }
    if(right != -1){
        if(heap->array[right] > heap->array[max] ){
            max = right;
        }
    }
    else{
        max = index;
    }
    if(max != index){
        temp = heap->array[index];
        heap->array[index] = heap->array[max];
        heap->array[max] = temp;
        Reheap_Down(heap,max);
    }
    //Reheap_Down(heap,max);
}
void Heap_Sort(bheap** h){
    int oldsize,i,temp;
    oldsize = (*h)->count;
    int n = (*h)->count-1;
    for(int j=(n-1)/2; j >= 0; j--){
        Reheap_Down((*h),j);
    }
    for(i = oldsize-1; i>0; i--){
        temp = (*h)->array[0];
        (*h)->array[0] = (*h)->array[(*h)->count-1];
        (*h)->array[0] = temp;
        (*h)->count--;
        Reheap_Down((*h),0);
    }
    (*h)->count = oldsize;
}
int Parent(bheap* heap, int index){
    if(index <= 0 || index >= heap->count){
        return -1;
    }
    return (index-1)/ 2;
    //remember the parentheses
}
int Left_Child(bheap* heap, int index){
    //remember the parentheses
    int left = 2*index+1;
    if(left >= heap->count){
        return -1;
    }
    return left;
}
int Right_Child(bheap* heap, int index){
    //remember the parentheses
    int right = 2*index+2;
    if(right >= heap->count){
        return -1;
    }
    return right;
} 
int Delete_Max(bheap* heap){
    int data;
    if(heap->count == 0){
        return -1;
    }
    data = heap->array[0];
    heap->array[0] = heap->array[heap->count - 1];
    heap->count--;
    Reheap_Down(heap,0);
    return data;
}
int Delete_Min(bheap* h){
    int data;
    if(h->count == 0){
        return -1;
    }
    data = h->array[0];
    h->array[0] = h->array[h->count-1];
    h->count--;
    Reheap_Down(h,0);
}
void Resize_Heap(bheap* heap){
    //both of these functions work
     int *array_old = heap->array;
    heap->capacity = heap->capacity * 2;
    heap->array = malloc(heap->capacity * sizeof(int));
    assert(heap->array != NULL);
    for(int i = 0; i < heap->capacity; i++){
        heap->array[i] = array_old[i];
    }
    free(array_old);
    //heap->capacity *= 2;
    //heap->array = realloc(heap->array, heap->capacity * sizeof(int));
}
int Get_Max(bheap* heap){
    if(heap->count == 0){
        return -1;
    }
    return heap->array[0];
}
int Get_Min(bheap*h){
    if(h->count == 0){
        return -1;
    }
    return h->array[0];
}
void Display_Bheap(bheap* heap){
    int i = 0;
    while(i < heap->count){
        printf("%d ", heap->array[i]);
        i++;
    }
    printf("\n%d items\n",heap->count);
}
void Destroy_Bheap(bheap* h){
    if(h == NULL){
        return;
    }
    free(h->array);
    free(h);
    h = NULL;
    printf("heap Destroyed\n");
}
int Find_Min_in_Maxheap(bheap* h){
    int min = h->array[0];
    for(int i = (h->count+1)/2; i < h->count; i++){
        if(h->array[i] < min){
            min = h->array[i];
        }
    }
    return min;
}
int Delete_index(bheap* h,int index ){
    int key;
    if(h->count-1 < index){
        printf("Index is Out of Range");
        return;
    }
    key = h->array[index];
    h->array[index] = h->array[h->count-1];
    h->count--;
    Reheap_Down(h,index);
    return key;
}