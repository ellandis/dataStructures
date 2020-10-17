#include<stdio.h>
#include "graph.h"
#include "dqueue.h"

int main(int argc, char* argv[]){
    int vert,edg,source,dest,dist;
	adjlist *graph;
	FILE *fp = fopen(argv[1],"r");
	if(argc < 2){
		perror("Missing file:");
	}
	fscanf(fp,"%d %d", &vert, &edg);
	printf("Vertexes: %d\nEdges:  %d\n",vert,edg);
	fscanf(fp,"%d %d %d",&vert,&edg, &dist);
	while(!feof(fp)){
		printf("From %d to %d: miles total: %d\n",vert,edg,dist);
		fscanf(fp,"%d %d %d",&vert,&edg, &dist);
	}
    return 0;
}