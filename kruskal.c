#include<stdio.h>> 
int parent[10]; 
void union_Edge(int ,int ); 
int find(int i); 
int find(int i) 
{ 
while (parent[i] != i) 
i = parent[i]; 
return i; 
} 
void union_Edge(int i,int j) 
{ 
int u = find(i); 
int v = find(j); 
parent[u] = v;  
} 
void kruskal(int graph[10][10], int n) 
{ 
int mincost = 0; // Cost of min MST 
// Initialize sets of disjoint sets 
for (int i = 0; i< n; i++) 
parent[i] = i; 
// Include minimum weight edges one by one 
int edge_count = 0; 
printf("..............................\n"); 
printf("  Edges Cost   \n"); 
printf("..............................."); 
while (edge_count< n - 1) 
{ 
int min = 99, u =0, v=0 ; 
for (int i = 0; i< n; i++) 
{ 
for (int j = 0; j < n; j++) 
{ 
if (find(i) != find(j) && graph[i][j] < min) 
{ 
min = graph[i][j]; 
u = i; 
v = j; 
} 
} 
} 
union_Edge(u, v); 
printf("\n Edge %d:(%d --> %d) cost = %d \n",edge_count++, u, v, min); 
mincost += min; 
} 
printf("..............................\n"); 
printf(" Total Minimum cost = %d \n", mincost); 
printf("..............................\n"); 
} 
void main() 
{ 
int graph[10][10]; 
int i,j,n; 
printf("......................................\n"); 
printf(" Program 1: Demo - Kruskal's Algorithm \n"); 
printf("......................................\n"); 
printf("Enter the number of vertices : "); 
scanf("%d",&n); 
printf("\n"); 
printf("Enter the weighted adjacency matrix\n"); 
for(i=0;i<n;i++) 
for(j=0;j<n;j++) 
scanf("%d",&graph[i][j]); 
kruskal(graph,n); 
} 