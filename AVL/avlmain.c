#include <stdio.h>
#include "avl.h"
#include "avlque.h"

int main(int argc, char* argv[]){
    avl* root = NULL;
    int num = 0;

    FILE *fp = fopen(argv[1],"r");
    if(argc < 2){
        perror("Missing File:");
    }
    fscanf(fp,"%d",&num);
    while(!feof(fp)){
        root = Insert_Node(root,root,num);
        fscanf(fp,"%d",&num);
    }
    Display_LevelOrder(root);
    return 0;
}