#include "sol.h"
#include <stdlib.h>
#include <stddef.h>

/**
typedef struct {
int from , to ;
int weight ;
} Edge ; **/
//==============================================
//call these functions to get the graph data:
//returns N –- the number of vertices in the graph
/**
int getVerticesCount ();**/
//reads the next edge from the edge list
//if there is next edge, returns 1 and stores that edge to *oEdge
//if there is no next edge, returns 0 without touching pointer
/**
int readEdge ( Edge * oEdge );**/
//==============================================
//implement these functions in your solution:
//this function is called first to initialize graph
//you are expected to read graph here and fill internal data structures
typedef struct point {
int power;
Edge* edg;
} point;
point all[300001];
Edge edges[300001];
void init (){
    int i, k = 0, oh;
    while (readEdge(&edges[k]) == 1){
        k++;
    }
    for (i = 0; i < 300001; i++){
        all[i].power = 0;
        all[i].edg = NULL;
    }
    for (i = 0; i < k; i++){
        int a = edges[i].from;
        int b = edges[i].to;
        /*if (edges[i].from == edges[i].to){
            all[edges[i].from].power += 2;
            all[edges[i].from].edg = (Edge*)realloc(all[edges[i].from].edg, sizeof(Edge)*(all[edges[i].from].power));
            all[edges[i].from].edg[all[edges[i].from].power-1] = edges[i];
            all[edges[i].from].edg[all[edges[i].from].power] = edges[i];
        }
        else{*/
            all[a].power++;
            all[a].edg = (Edge*)realloc(all[a].edg, sizeof(Edge)*(all[a].power));
            oh = all[a].power - 1;
            all[a].edg[oh] = edges[i];

            all[b].power++;
            all[b].edg = (Edge*)realloc(all[b].edg, sizeof(Edge)*(all[b].power));
            oh = all[b].power - 1;
            all[b].edg[oh] = edges[i];
//
        //}
    }
}
//returns number of edges indicent to vertex iVertex
int getEdgesCount ( int iVertex ){
    return all[iVertex].power;
}
//returns iIndex-th edge incident to the vertex iVertex
//it must have .from == Vertex and .to denoting the other end
Edge getIncidentEdge (int iVertex , int iIndex ){
    Edge res = all[iVertex].edg[iIndex];
    if (res.from != iVertex) {
    int copy = res.from;
    res.from = iVertex;
    res.to = copy;
    }
    return res;
}
