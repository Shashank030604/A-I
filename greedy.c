 
#include<stdio.h> 
int main() 
{ 
     float weight[50],profit[50],ratio[50],x[50],tp=0.0,temp,capacity; 
     int n,i,j; 
     printf("Enter the number of items :"); 
     scanf("%d",&n);    
     for (i = 0; i < n; i++) 
       { 
        printf("Enter Weight and Profit for item[%d] :\n",i); 
        scanf("%f %f", &weight[i], &profit[i]); 
       }  
    printf("Enter the capacity of knapsack :\n"); 
    scanf("%f",&capacity); 
      
     for(i=0;i<n;i++) 
         ratio[i]=profit[i]/weight[i]; 
          
        printf ("\n Given Data and its ratio (pi/wi): \n"); 
        printf (" -----------------------------------------------\n"); 
        printf (" Item No.     w[i]      p[i]       p[i]/w[i]     \n"); 
        printf (" ------------------------------------------------\n"); 
        for (i = 0; i < n; i++)  
           { 
             printf ( " %d\t %f\t %f\t %f \n", i, weight[i], profit[i], ratio[i]) ; 
             } 
        printf (" ----------------------------------------------\n"); 
       
      /* To arrange in decreasing order of ratio */      
          
    for (i = 0; i < n; i++)  
      for (j = i + 1; j < n; j++)  
         if (ratio[i] < ratio[j])  
        { 
            temp = ratio[j]; 
            ratio[j] = ratio[i]; 
            ratio[i] = temp; 
  
            temp = weight[j]; 
            weight[j] = weight[i]; 
            weight[i] = temp; 
  
            temp = profit[j]; 
            profit[j] = profit[i]; 
            profit[i] = temp; 
         } 
     
        printf ("\n After rearranging the data in descending order based on ratio (pi/wi): \n"); 
        printf (" -----------------------------------------------\n"); 
        printf (" Item No.     w[i]      p[i]       p[i]/w[i]    \n"); 
        printf (" ------------------------------------------------\n"); 
        for (i = 0; i < n; i++)  
             { 
               printf ( " %d\t %f\t %f\t %f \n", i, weight[i], profit[i], ratio[i]) ; 
              } 
        printf (" ----------------------------------------------\n"); 
 
 printf("Knapsack problem using Greedy Algorithm:\n"); 
     for (i = 0; i < n; i++)  
      { 
           if (weight[i] > capacity) 
             break; 
         else  
           { 
            x[i] = 1.0; 
        tp= tp + profit[i]; 
            capacity = capacity - weight[i]; 
            } 
        }  
     
        if (i < n) 
     { 
                 tp = tp + (ratio[i]*capacity); 
                 x[i] = capacity / weight[i]; 
               } 
          
     printf("The solution vector is: { "); 
     for (i = 0; i < n; i++) 
     printf("%f   ", x[i] ); 
     printf("}"); 
 
     printf("\nThe maximum profit gained :%f\n",tp);      
     return 0; 
}