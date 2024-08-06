 
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
    
   int partition(int a[], int low, int high); 
   void swap(int a[],int i,int j); 
    
  void QuickSort(int a[], int low, int high) 
    { 
        if (low<high) 
      { 
          int s=partition(a,low,high); 
          QuickSort(a,low,s-1); 
          QuickSort(a,s+1,high); 
      } 
    } 
 
 
  int partition(int a[], int low, int high) 
     { 
         int pivot, i, j; 
         pivot=a[low]; 
         i=low+1; 
         j=high;  
         while(low<high) 
         { 
              while(a[i]<=pivot && i<high)    i++; 
               while(a[j] > pivot)            j--; 
                   if (i<j )    swap(a,i,j);  
                   else  
                         { 
                        swap(a,low,j); 
                        return j; 
                        } 
             } 
         return j; 
     } 
 
 
void swap(int a[],int i,int j) 
{ 
    int temp; 
    temp = a[i]; 
    a[i]=a[j]; 
    a[j]=temp; 
} 
 
 
 
 
void  printArray(int a[], int n) 
    { 
     printf("\n -------------------------------------------\n"); 
     for(int i=0;i<n;i++) 
       printf("%d \t", a[i]); 
      printf("\n ------------------------------------------"); 
    } 
 
    
int main() 
{ 
       int i,n; 
       double tim[10];  
       printf("       Quick Sort Demo :\n "); 
       printf("\n -------------------------\n"); 
       printf("Enter the array size :  "); 
       scanf("%d",&n); 
 
       int a[n]; 
              
       printf("Enter the array elements:");  
       for(i=0;i<n;i++) 
        scanf("%d",&a[i]); 
             
       printf("\n\n Before sorting : \n "); 
       printArray(a, n); 
       QuickSort(a, 0, n); 
       printf("\n\n After sorting : \n "); 
       printArray(a, n); 
        
       printf( "\n\n------------------Quick Sort Demo for  N > 5000 -------------"); 
       printf( "\n \t Value of N   \t   Time (in Milli Seconds)"); 
       printf( "\n----------------------------------------------------------------\n");  
       int N=6000;    
 
       for(int count=0;count<10;count++) 
         {  
          int a[N];  
        //Generate n random numbers and store them in array  
         for (int i = 1; i <= N; i++)  
               {  
               a[i] = rand() % N+1;  
                }           
   
        // using clock_t to store time  
         clock_t start, end;  
                     
         start = clock();  
         QuickSort(a, 0, N); 
         end = clock();  
        
         tim[count] = ((double)(end - start));  
         printf("\t %li \t\t\t %li\n",  N, (long int)tim[count]);  
         N += 1000;                                         
       }     
      printf( "\n----------------------------------------------------------------\n");  
      return 0; 
  }