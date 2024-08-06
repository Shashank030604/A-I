 
#include<stdio.h> 
void main() 
{ 
         int n,i,j,k, min, w[10][10],d[10][10][10];  
            printf("Enter the number of vertices in the graph  :  "); 
             scanf("%d",&n); 
            
            printf("Read the Cost/Weight matrix: \n"); 
            for(i=1;i<=n;i++) 
            for(j=1;j<=n;j++) 
            scanf("%d",&w[i][j]); 
            
// Initialise D[0] with  w[i,j] 
              for(i=1;i<=n;i++) 
               for(j=1;j<=n;j++) 
                 d[0][i][j]=w[i][j]; 
                  
// Generate Distance transitive closure matrices D(1),D(2),....D(n) 
 
          for(k=1;k<=n;k++) 
             { 
             for(i=1;i<=n;i++) 
               { 
             for(j=1;j<=n;j++) 
                 { 
                     if (d[k-1][i][j] < d[k-1][i][k]+d[k-1][k][j]) 
                          min = d[k-1][i][j]; 
                     else 
                         min = d[k-1][i][k]+d[k-1][k][j]; 
                 d[k][i][j]= min; 
                    } 
                } 
              } 
               
             printf("\n Floyd's Demo : Series of Transitive Closure matrices \n"); 
             printf("-----------------------------------------------------\n"); 
            
             for(k=0;k<=n;k++) 
             { 
              printf("Distance Transitive Closure Matrix : D[%d]", k);    
              printf("\n-----------------------------------------------------\n"); 
              for( i=1;i<=n;i++) 
                  { 
               for(j=1;j<=n;j++) 
                 { 
                printf("%d \t", d[k][i][j]); 
                   } 
                 printf("\n"); 
                 } 
               } 
              printf("-----------------------------------------------------\n"); 
           }