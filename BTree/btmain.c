#include <stdio.h>
#include "btree.h"
#include "dqueue.h"

int main(int argc,  char *argv[])
{
    bt* root = NULL;
    int num=0,size,*p;
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
	printf("\n");
	Display_PreOrder(root);
	printf("\n");
	Display_InOrder(root);
	printf("\n");
	Display_PostOrder(root);
	printf("\n");
	int check = Find_Node(root,350);
	if(check == 1){
		printf("FOUND\n");
	}
	else
	{
		printf("Not FOUND\n");
	}
	printf("Max number is %d\n",Find_Max(root));
	printf("Height of the tree is %d\n",Find_Height(root));
	Deepest_Node(root);
	printf("The Sum of the Tree is %d\n",Add(root));
    return 0;
}
