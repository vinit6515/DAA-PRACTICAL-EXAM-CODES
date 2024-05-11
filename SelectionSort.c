#include<conio.h>
#include<stdio.h>
#include<time.h>
void SelectionSort(int arr [], int n){
    int i , j , min_index;
    clock_t start=0,end=0;
    start=clock(); 
    for(i=0;i<n-1;i++){
        min_index=i;
        for(j=i+1;j<n;j++){
            if(arr[j]>arr[min_index]){
                min_index=j;
            }
        }
        if(min_index!=i){
            int temp=arr[min_index];
            arr[min_index]=arr[i];
            arr[i]=temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n %d ", arr[i]);
    }
    
    end=clock();
    printf("Average Execution time is %lf ",((double)(end - start)) / (CLOCKS_PER_SEC));
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
    SelectionSort(arr,n);

}