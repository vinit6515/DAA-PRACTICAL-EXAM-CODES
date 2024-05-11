#include<stdio.h>
#include<conio.h>
void FloydWarshall(int n,int graph [][n]){
    int matrix [n][n];
    int i , j , k;
    for ( i = 0; i < n; i++)// Copying graph matrix in matrix
    {
        for ( j = 0; j < n; j++)
        {
            matrix[i][j]= graph[i][j];
        }
    }
    for(k=0;k<n;k++){
        for ( i = 0; i < n; i++)
        {
            for(j=0;j<n;j++){
                if(matrix[i][j]>matrix[i][k]+matrix[k][j])
                matrix[i][j]=matrix[i][k]+matrix[k][j];           
            }
        }
    }
    for ( i = 0; i <n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d  ",matrix[i][j]);
        }
            printf("\n");
    }
}
void main(){
int n,i,j;
printf("\nEnter number of vertices:");
scanf("%d",&n);
int graph[n][n];
printf("\nEnter the cost adjacency matrix:");
for ( i = 0; i < n; i++)
{
    for(j=0;j<n;j++){
        scanf("%d",&graph[i][j]);
    }
}
FloydWarshall(n,graph);
}
