#include<stdio.h>
#include<stdlib.h>
#include "dynA.h"

int main(int argc, char* argv[]){
    DA *dynArry = Create_DA();
    int size;
	int i,k=0,j=0;
	char *co;
	FILE *fp = fopen(argv[1],"r");
	if(argc < 2){
		perror("Missing file:");
	}
	size = sizeof(int);
	while(fscanf(fp,"%d",&i) != EOF){
		Insert_Item_Back(dynArry,i);
	}
	/*while (k < 5)
	{
		j = rand() % 55;
		Insert_Item_Front(dynArry,j);
		k++;
	}*/
	//Display_DA(&dynArry);
	//Insert_Item_Pos(dynArry,4,3);
    //Display_DA(&dynArry);
	//Insert_Item_Pos(dynArry,10,999);
	Delete_Item_Front(dynArry);
	Delete_Item_Back(dynArry);
	Display_DA(&dynArry);
	Sort(dynArry);
	Display_DA(&dynArry);
	Free_DA(dynArry);
	
}