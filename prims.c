 
#include<stdio.h> 
#include<stdbool.h>  
#define INF 9999999 
 
int main() 
 { 
     int n, W[10][10],visited[10], source, u, v, sum =0; 
   
     printf("Enter the number of vertices : "); 
scanf("%d",&n); 
 
printf("Enter the weighted graph : \n"); 
for(int i=0;i<n;i++) 
for(int j=0;j<n;j++) 
scanf("%d",&W[i][j]); 
 
printf("Enter the source vertex : "); 
scanf("%d",&source); 
 
  // set visited false initially 
  memset(visited, false, sizeof(visited)); 
   
 visited[source] = true; 
 
 printf("Edge  : Weight \n"); 
 for ( int no_edge = 0; no_edge < n - 1; no_edge++ )  
   { 
int min = INF; 
u = 0; 
v = 0; 
for (int i = 0; i < n; i++)  
  { 
    if (visited[i])  
        { 
         for (int j = 0; j < n; j++)  
            { 
           if (!visited[j] && W[i][j]) 
              {   
              if (min > W[i][j])  
                { 
                  min = W[i][j]; 
                  u = i; 
                  v = j; 
                } 
                      } 
                   } 
               } 
           } 
     
 
    printf("%d - %d : %d\n", u, v, W[u][v]); 
    visited[v] = true; 
     
    sum=sum + min;  
       
         } 
  printf("\nThe total cost of minimum spanning tree is : %d ",sum); 
  return 0; 
 }