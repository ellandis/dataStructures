#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <stdio.h>
#include "dqueue.h"

typedef struct AdjGraph adjmatrix;
extern adjmatrix* Create_Adj_Graph(int);
extern void aDFS(adjmatrix*,int);
extern void aBFS(adjmatrix*,int);
extern void Display_Graph(adjmatrix*);
extern adjmatrix* Add_Edge(adjmatrix**,int,int);



typedef struct AdjList adjlist;
typedef struct LinkNode lnode;

extern adjlist* Create_List_Graph(int,int,int);
extern void lDFS(adjlist*,int);
extern void lBFS(adjlist*,int);
extern void Display_Graph_Lists(adjlist*);
extern void DFStraversal(adjlist*);

#endif