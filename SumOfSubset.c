#include<conio.h>
#include<stdio.h>
#include<stdbool.h>
bool isSubsetSSum(int set[], int n , int sum){
    if(sum==0)
    return true;
    if(n==0)
    return  false;
    if(set[n-1]>sum){
        
        return isSubsetSSum(set, n-1, sum);
    }
    return isSubsetSSum(set,n-1,sum) || isSubsetSSum(set,n-1,sum-set[n-1]);
}
void main(){
    int set[100], sum,n;
    printf("\nEnter the number of sets: ");
    scanf("%d",&n);
    printf("\nEnter the sum required: ");
    scanf("%d",&sum);
    printf("\nEnter the set matrix:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    if(isSubsetSSum(set,n,sum)){
        printf("\nThe sum is found in the set.");
   }
   else{
    printf("\nThe sum is not found in the set.");
   }
}