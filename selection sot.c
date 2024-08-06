 
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
 
void SelectionSort(long int a[], int n) 
 { 
    for (int i = 0; i <= n-2; i++)   
        {   
          long int min = i; 
            for (int j = i + 1; j <= n-1; j++) 
            {   
                if (a[j] < a[min]) 
                {   
                    min = j;  
                }   
            }   
            long int temp = a[min];    
            a[min] = a[i];   
            a[i] = temp;   
        }   
    }   
   
   
void print(long int a[],int n) 
 { 
 for(int i=0;i<n;i++) 
 printf("%d \t", a[i]); 
 } 
 
 
int main()  
{  
    // Array to store time duration  
       double tim[10];  
        
       int i,n; 
       printf("Enter the array size :  "); 
       scanf("%d",&n); 
 
       long int a[n]; 
              
       printf("Enter the array elements:");  
       for(i=0;i<n;i++) 
        scanf("%d",&a[i]); 
             
       printf("\n\n Before sorting : \n "); 
       print(a,n); 
             
       SelectionSort(a,n); 
      
       printf("\n\n After sorting: \n"); 
       print(a,n); 
       
      
     printf( "\n\n------Selection Sort Demo for  N > 5000 -------------"); 
     printf( "\n Value of N   \t   Time (in Milli Seconds)"); 
     printf( "\n----------------------------------------------------------------\n");  
      
        long int N=6000;    
 
       for(int count=0;count<10;count++) 
         {  
           long int a[N];  
        //Generate n random numbers and store them in array a 
         for (int i = 1; i <= N; i++)  
            {  
             a[i] = rand() % N+1;  
                  }           
   
        // using clock_t to store time  
         clock_t start, end;  
                     
         start = clock();  
         SelectionSort(a, N);  
         end = clock();  
        
         tim[count] = ((double)(end - start));  
         printf("%li \t\t\t %li\n",  N, (long int)tim[count]);  
         N += 1000;                                         
       }     
   printf( "\n----------------------------------------------------------------\n");  
    return 0;  
}