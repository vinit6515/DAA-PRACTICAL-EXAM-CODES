#include<conio.h>
#include<stdio.h>
int min,max;
int a[100];
void minmax(int i , int j){ // This is our main function where we will be apllying the logic
    int min1, max1,mid;
    if(i==j){
        min=max=a[i];
    }
    else{
        if(i==j-1){
            if(a[i]>a[j]){
                min=a[j];
                max=a[i];
            }
            else{
                min=a[i];
                max=a[j];
            }

        }
        else{
            mid=(i+j)/2;
            minmax(i,mid);
            max1=max;min1=min;
            minmax(mid+1,j);
            if(max1>max){
                max=max1;
            }
            if(min1<min){
                min=min1;
            }
        }
    }
}
void main(){
    int n,i; 
    printf("\nEnter the total numbers you are going to enter:");
    scanf("%d",&n);
    printf("\nEnter the numbers:");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    minmax(0,n-1);
    printf("\nThe maximum number is : %d",max);
    printf("\nThe minimum number is : %d",min);
    
}