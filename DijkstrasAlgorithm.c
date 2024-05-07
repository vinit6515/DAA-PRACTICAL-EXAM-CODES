#include<conio.h>
#include<stdio.h>

void main(){
    int i , j , n, source;
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    int cost [n][n];
    int dist[n];
    printf("\nEnter the cost matrix:");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
        
    }
    printf("\nEnter the source vertex:");
    scanf("%d",&source);
    dijkstra(source,n,cost,dist);
    print(source,dist,n);


    
}
void print(int s , int dist [], int n){
    printf("\nShortest path from %d is :\n", s);
    for (int i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n", s, i , dist[i]);

    }
    
}
void dijkstra(int source , int n,int cost[][n], int dist []){
    int i , j , v , count =0, min, visited[100];
    for ( i = 0; i < n; i++)
    {
        visited[i]=0;
    }
    visited[source]=1;
    dist[source]=0;
    while (count<n)
    {   min=999;
        for ( i = 0; i < n; i++)
        {
            if(min>dist[i]&& visited[i]==0){
                min=dist[i];
                v=i;

            }
            
        }
        visited[v]=1;
        count ++;
        for ( i = 0; i < n; i++)
        {
            if(dist[i]>dist[v]+ cost[v][i]){// Principle of relaxation
                dist[i]=dist[v]+ cost[v][i];
            }
        }
        
        
    }
    
    
}