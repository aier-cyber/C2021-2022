#include "sol.h"
#include <stdlib.h>
#include <time.h>

typedef struct Inc {
int vertex, countOfInc, capacity;
Edge* incTo;
} ListOfInc;

ListOfInc graph[301000] = { 0 };
Edge edges[301000] = { 0 };

//this function is called first to initialize graph
//you are expected to read graph here and fill internal data structures
void init() {
int M = 0;
while (readEdge(&edges[M]) == 1) {
M++;
}
int N = getVerticesCount();
for (int i = 0; i < 301000; i++) {
graph[i].capacity = 1;
graph[i].countOfInc = 0;
graph[i].vertex = i;
graph[i].incTo = (Edge*)malloc(sizeof(Edge));
}
for (int i = 0; i < M; i++) {
int idFrom = edges[i].from;
int idTo = edges[i].to;

if (graph[idFrom].capacity < graph[idFrom].countOfInc + 1) {
graph[idFrom].capacity = graph[idFrom].capacity + 2;
graph[idFrom].incTo = (Edge*)realloc(graph[idFrom].incTo, sizeof(Edge) * graph[idFrom].capacity);
}
graph[idFrom].incTo[graph[idFrom].countOfInc] = edges[i];
graph[idFrom].countOfInc++;

if (graph[idTo].capacity < graph[idTo].countOfInc + 1) {
graph[idTo].capacity = graph[idTo].capacity + 2;
graph[idTo].incTo = (Edge*)realloc(graph[idTo].incTo, sizeof(Edge) * graph[idTo].capacity);
}
graph[idTo].incTo[graph[idTo].countOfInc] = edges[i];
graph[idTo].countOfInc++;
}
}

//returns number of edges indicent to vertex iVertex
int getEdgesCount(int iVertex) {
return graph[iVertex].countOfInc;
}

//returns iIndex-th edge incident to the vertex iVertex
//it must have .from == Vertex and .to denoting the other end
Edge getIncidentEdge(int iVertex, int iIndex) {
Edge res = graph[iVertex].incTo[iIndex];
if (res.from != iVertex) {
int temp = res.from;
res.from = iVertex;
res.to = temp;
}
return res;
}
