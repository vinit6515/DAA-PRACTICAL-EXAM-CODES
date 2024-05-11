#include<stdio.h>
#include<conio.h>
#include<time.h>
void InsertionSort(int arr [], int n){
    int i , j , key;
    clock_t start=0,end=0;
    start=clock();
    for (i = 1; i < n; i++)
    {
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>key)
        {   
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;    
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n %d ",arr[i]);
    }
    end=clock();
    printf("\nThe execution time for Insertion Sort is %lf", ((double)end-start)/ (CLOCKS_PER_SEC));
}
void main(){
    int arr[100];
    int n ;
    printf("\nEnter Number of Elements in an array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of an array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    InsertionSort(arr,n);
}