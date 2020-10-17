#include <stdio.h>
#include "bst.h"
#include "bstque.h"

int main(int argc,  char *argv[])
{
    bst* root = NULL;
    int num=0;
	FILE *fp = fopen(argv[1],"r");
	if(argc < 2){
		perror("Missing file:");
	}
	fscanf(fp,"%d",&num);
	while(!feof(fp)){
		//root = Insert_Node(root,num);
		Insert_Node(&root,num);
		fscanf(fp,"%d",&num);
	}
    Display_LevelOrder(root);
    Find_Kth(root,9,4);
	printf("\n");
	
    return 0;
}