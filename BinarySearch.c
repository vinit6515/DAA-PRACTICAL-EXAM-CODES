#include<conio.h>
#include<stdio.h>
int BinarySearch (int arr [], int low , int high , int x){
    int mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if (arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x){
            return BinarySearch(arr,low, mid-1,x);
        }
        else if(arr [mid]<x){
            return BinarySearch(arr,mid+1,high,x);
        }
        else{
            return -1;
        }
        
    }
}
void main (){
    int arr [100];
    int n , i , j ,x;
    printf("\nEnter the number you wish to search:");
    scanf("%d",&x);
    printf("\nEnter the number of elements :");
    scanf("%d",&n);
    printf("\nEnter the array in a sorted order:");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    j= BinarySearch(arr, 0,n,x);
    if(j==-1){
        printf("\nNo match found");
    }
    else{
        printf("\n Match found at %d location",j);
    }
}