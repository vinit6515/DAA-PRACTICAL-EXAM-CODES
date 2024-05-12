#include<conio.h>
#include<stdio.h>
#define d 256
#include<string.h>
void search(char pat[], char txt[], int q){
    int M= strlen(pat);
    int N = strlen(txt);
    int p=0,t=0,h=1,i,j;
    for(i=0;i<M-1;i++){
        h=(h*d)%q;
    }
    for ( i = 0; i < M; i++)
    {
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
    for (i = 0; i <= N-M; i++)
    {
        if (p==t)
        {
            for(j=0;j<M;j++){
                if(pat[j]!=txt[i+j]){
                    break;
                }
            }
            if(j==M){
                printf("\nPattern is found at index %d",i);
            }
        }
        if(i<N-M){
            t=(d*(t-txt[i]*h)+ txt[i+M])%q;
            if(t<0){
                t=t+q;
            }
        }
        
    }
}
void main(){
    char pat[100], txt[100];
    int q;
    printf("\nEnter the text: ");
    gets(txt);
    printf("\nEnter the pattern: ");
    gets(pat);
    printf("\nEnter the hash value: ");
    scanf("%d",&q);
    search(pat,txt,q);
}