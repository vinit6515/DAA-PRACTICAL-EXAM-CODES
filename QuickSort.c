#include<conio.h>
#include<stdio.h>
#include<time.h>
int partition (int arr[], int low , int high){
    int pivot=arr[low];
    int start=low+1;
    int end = high ;
    while (end>start)
    {
        while(pivot>=arr[start]){
            start++;
        }
        while (arr[end]>pivot)
        {
            end--;
        }
        if(end>start){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
        int temp=arr[low];
        arr[low]=arr[end];
        arr[end]=temp;
        return end;
    }
}
void QuickSort(int arr[], int low , int high ){
    
    if(high>low)
    {
        int loc=partition(arr,low, high);
        QuickSort(arr,low,loc-1);
        QuickSort(arr,loc+1,high);
    }   
}
void main(){
    int arr[100];
    int n ;
    clock_t start=0, end=0;
    printf("\nEnter Number of Elements in an array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of an array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    start=clock();
    QuickSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", arr[i]);
    }
    end=clock();
    printf("\nThe execution time for Quick Sort Algorithm is : %lf",((double)end-start)/(CLOCKS_PER_SEC));

}