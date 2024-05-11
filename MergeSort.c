#include<conio.h>
#include<stdio.h>
#include<time.h>
void merge(int arr[], int l, int m , int r){
    int i , j , k , n1, n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1], R[n2];
    for(i=0;i<n1;i++)
    L[i]=arr[l+i];
    for(i=0;i<n2;i++)
    R[i]=arr[m+1+i];
    i =0, j=0 , k =l;
    while(i<n1 && j <n2 ){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[], int l, int r){
    if(r>l){
        int m =l + (r-l)/2;
        MergeSort(arr,l, m);
        MergeSort(arr,m+1,r);
        merge(arr, l, m , r);
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
    MergeSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", arr[i]);
    }
    end=clock();
    printf("\nThe execution time for Merge Sort Algorithm is : %lf",((double)end-start)/(CLOCKS_PER_SEC));
}