#include<stdio.h>
#include<stdbool.h>
#define INF 9999
int main(){
    int n ,G[100][100];
    bool selected[100];
    printf("\nEnter number of edges:\n");
    scanf("%d",&n);
    printf("\nEnter the graph matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
    for (int i = 0; i <n; i++)
    {
        selected[i]=false;
    }
    selected[0]=true;
    int  sum=0;
    int no_of_edges=0, x , y ;
    printf("\nEdge : Weight\n");
    while (no_of_edges<n-1)
    {
        int min=INF;
        x=0; y=0;
        for(int i=0;i<n;i++){
            if(selected[i]){
                for(int j =0;j<n;j++){
                    if(!selected[j]&&G[i][j]){
                        if (min>G[i][j])
                        {
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                        
                    }
                }
            }
        }
        printf("%d->%d : %d\n",x,y,G[x][y]);
        sum+=G[x][y];
        selected[y]=true;
        no_of_edges++;
    }
    printf("\nMinimum Spanning tree cost is %d",sum);
}