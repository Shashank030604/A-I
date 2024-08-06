 
#include<stdio.h> 
 
 int max(int a, int b)  
    {  
        return (a > b)? a : b;  
    } 
 
int knapSack(int W, int w[], int v[], int n) 
    { 
        int i, j; 
        int V[n+1][W+1]; 
 
 // Build table in bottom up manner 
        for (i = 0; i <= n; i++) 
        { 
            for (j= 0; j <= W; j++) 
            { 
                if (i==0 || j==0) 
                    V[i][j] = 0; 
                else if (w[i-1] <= j) 
                    V[i][j] = max(v[i-1] + V[i-1][j-w[i-1]],  V[i-1][j]); 
                else 
                    V[i][j] = V[i-1][j]; 
            } 
        } 
 
// Constructed Table using Dynamic Programming 
printf("\n...................................................\n");     
  printf("      Table Constructed using Dynamic Programming    "); 
  printf("\n...................................................\n");      
        for (i = 0; i <= n; i++) 
        { 
            for (j= 0; j <= W; j++) 
            { 
                printf("%d \t", V[i][j]); 
            } 
        printf("\n "); 
        } 
   printf("\n...................................................\n");      
        
 // Find Item which is inserted into the Knapsack 
         int x[5]; 
         i=n;j=W; 
        while(i!= 0 && j !=0) 
           { 
            if(V[i][j]!=V[i-1][j]) 
            { 
                x[i]=1; 
                j=j-w[i-1]; 
            } 
            x[i]=0; 
        i--; 
        } 
 
//Display Solution Vector    
  printf(" Solution Vector: "); 
     for(i=1;i<=n;i++) 
        printf("x[%d]= %d ",i,x[i]); 
       
// Return optimal profit 
    return V[n][W]; 
    } 
   
  int main() 
    {   
        int n, wt[10],val[10], W ;     
   
        printf("\n 0/1 Knapsack Using Dynamic Programming \n"); 
        printf("................................................................\n"); 
 
        printf("Enter the number of items: "); 
        scanf("%d",&n);  
 
        printf("Enter the weights: "); 
        for(int i=0; i<n; i++) 
        scanf("%d",&wt[i]);  
 
        printf("Enter the values: ");        
for(int i=0; i<n; i++) 
scanf("%d",&val[i]); 
 
printf("Enter the maximum capacity: "); 
scanf("%d",&W);  
         
int opt =  knapSack(W, wt, val, n) ;   
        
printf("\n Optimum Profit is V[n,W]= V[%d,%d]= %d", n, W, opt);  
printf("\n...................................................................\n");   
return 0;    
   }