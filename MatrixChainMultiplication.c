#include<stdio.h>
#include<conio.h>

int MatrixChainOrder(int arr[], int i , int j){
    if(i==j){
        return 0;
    }
    int k , count =0 , min = 99999;
    for(k=i;k<j;k++){
        count=MatrixChainOrder(arr, i , k)+ MatrixChainOrder(arr,k+1,j)+(arr[i-1]*arr[j]*arr[k]);
        if (min>count)
        {
            min = count;
        }
        
    }
    return min;
}

void main(){
    int arr[100], n ;
    printf("\nEnter the number of Matrices:");
    scanf("%d",&n);
    printf("\nEnter the matrix array :");
    for ( int i = 0; i < n+1; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nThe minimum number of calculations required are : %d ", MatrixChainOrder(arr, 1,n));
    
}