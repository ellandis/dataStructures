#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "graph.h"
#include "dqueue.h"

//adjaceny matrix Graph
struct AdjGraph{
    char name;
    int Vertices;
    int Edges;
    int **Adj;
};
adjmatrix* Create_Adj_Graph(int v){
    int i,u,y,j,e;
    adjmatrix* g = malloc(sizeof(adjmatrix*));
    assert(g != NULL);
    g->Vertices = v;
    g->Adj = malloc(g->Vertices * sizeof(adjmatrix));
    //g->Adj = malloc(sizeof(g->Vertices * g->Vertices));
    for(j = 0; j < g->Vertices; j++){
        g->Adj[j] = malloc(g->Vertices * sizeof(adjmatrix));
        for(int k=0; k < g->Vertices; k++){
            g->Adj[j][k] = 0;
        }
    }
    printf("Enter the number of Edges: ");
    scanf("%d",&e);
    g->Edges = e;
    for(i=0; i < g->Edges; i++){
        do{
            printf("Enter Edge: ");
            scanf("%d %d",&u,&y);
        }while(u > g->Vertices || y > g->Vertices || u<0 || y<0);
        Add_Edge(&g,u,y);
    }
    return g;
}
adjmatrix* Add_Edge(adjmatrix** g, int i, int j){
     //for Undirected graphs set both the bits
    (*g)->Adj[i][j] = 1;
    (*g)->Adj[j][i] = 1;
    return (*g);
}

void Display_Graph(adjmatrix* graph){
    int i,j;
    int ascii = 65;
    printf("\t[A]\t[B]\t[C]\t[D]\n");
    for(i=0; i< graph->Vertices; i++){
        graph->name = ascii + i;
        printf("{%c}->",graph->name);
        for(j=0; j < graph->Vertices; j++){
            printf("\t[%d] ",graph->Adj[i][j]);
        }
        printf("\n");
    }
}

//Linked List Graph
struct AdjList{
    int Vertices;
    int Edges;
    lnode** map;
};
struct LinkNode{
    int hometown;
    int visited;
    int distance;
    lnode* roads;
};
struct DQueue{
    int *array;
    int front,rear;
    int capacity;
};
adjlist* Create_List_Graph(int source, int dest, int dist){
    int i,x,y,vert,edge;
    lnode *temp, *last;
    //create graph
    adjlist *g = malloc(1 * sizeof(adjlist));
    assert(g != NULL);
    //create Vertex array
    printf("# of Vertices: \n");
    scanf("%d",&vert);
    g->Vertices = vert;
    g->map = malloc(g->Vertices * sizeof(lnode));
    assert(g->map != NULL);
    //create node for each index in vertex array
    for(i=0; i < g->Vertices; i++){
        g->map[i] = malloc(sizeof(lnode));
        g->map[i]->hometown = i;
        g->map[i]->roads = NULL;
        g->map[i]->visited = 0;
    }
    //Create and Connect edges
    printf("# of Edges: \n");
    scanf("%d",&edge);
    g->Edges = edge;
    for(i=0; i< g->Edges; i++){
        do{
            printf("Reading Edge: ");
            scanf("%d %d", &x, &y);
        }while(x >= g->Vertices || y >= g->Vertices || x < -1 || y < -1);
        last = malloc(sizeof(lnode));
        temp = malloc(sizeof(lnode));
        temp->hometown = y;
        temp->visited = 0;
        temp->roads = NULL;
        //this way below puts the new item in front
        //temp->roads = g->map[x]->roads;
        //g->map[x]->roads = temp;
        last->roads = g->map[x]->roads;
        if(last->roads != NULL){
            while(last->roads != NULL){
                last = last->roads;
            }
            last->roads = temp;
        }
        else{
            last->roads = temp;
            g->map[x]->roads = last->roads;
        }
        printf("");
    }
    return g;
}

void Display_Graph_Lists(adjlist* g){
    int i;
    lnode *temp;
    for(i=0; i < g->Vertices; i++){
        temp = g->map[i];
        printf("hometown[%d] with roads to-> ",temp->hometown);
        while(temp->roads != NULL){
            temp = temp->roads;
            printf("%d->",temp->hometown);
        }
        printf("\n");
    }
}

void lDFS(adjlist* g, int start){
    lnode *newlist = g->map[start];
    lnode *temp = newlist;
    g->map[start]->visited = 1;
    printf("Visited %d \n", start);

    while(temp != NULL){
        int Connected_Vertex = temp->hometown;
        if(g->map[Connected_Vertex]->visited == 0){
            lDFS(g,Connected_Vertex);
        }
        temp = temp->roads;
    }
}
void lBFS(adjlist *g, int start){
    dque* que = Create_DQueue();
    g->map[start]->visited = 1;
    Enqueue(que,start);

    while(!Is_Empty(que)){
        //printf("%d, ", Dequeue(que));
        int currentVertex = Dequeue(que);
        printf("Visited %d\n",currentVertex);
        lnode* temp = g->map[currentVertex];
        while(temp){
            int adjVertex = temp->hometown;
            if(g->map[adjVertex]->visited == 0){
                g->map[adjVertex]->visited = 1;
                Enqueue(que,adjVertex);
            }
            temp = temp->roads;
        }
    }
}

/*
void DFStraversal(adjlist* g){
    int Visited[g->Vertices];
    for(int i=0; i < g->Vertices; i++){
        Visited[i] = 0;
    }
    for(int j=0; j < g->Vertices; j++){
        if(!Visited[j]){
            lDFS(g,j);
        }
    }
}*/