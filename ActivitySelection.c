#include<conio.h>
#include<stdio.h>
void ActivitySelection(int start [], int finish [],int n){
    int i=0 ,j , count =1;
    printf("%d ", i);// First process is always selected 
    for ( j = 1; j < n; j++)
    {
        if(start[j]>=finish[i]){
            printf("%d ",j);
            count ++;
            i=j;
        }
    }
    printf("\nThe total number oof activities taking place are %d", count);
    

}
void main(){
    int start[100], finish[100], n;
    printf("\nEnter the number of processes :");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the starting and finishing time of each process: ");
        scanf("%d %d",&start[i],&finish[i]);
    }
    ActivitySelection(start,finish,n);
}