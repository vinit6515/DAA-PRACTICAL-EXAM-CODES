#include<conio.h>
#include<stdio.h>

char S1[100], S2[100];
int LCS_Table[100][100];
void LCS(){
    int m=strlen(S1);
    int n = strlen(S2);
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            LCS_Table[i][j]=0;
        }
        
    }
    for(int i =0 ; i< m ;i++){
        for(int j =0 ; j < n ;j++){
            
            if(S1[i]==S2[j]){
                LCS_Table[i+1][j+1]=LCS_Table[i][j]+1;
            }
            else if(LCS_Table[i][j+1] >= LCS_Table[i+1][j]){
                LCS_Table[i+1][j+1]=LCS_Table[i][j+1];
            }
            else{
                LCS_Table[i+1][j+1]=LCS_Table[i+1][j];
            }
        }
    }
    int index = LCS_Table[m][n];
    char sequence[index+1];
    sequence[index]='\0';
    int i =m ; int j = n;
    while (i>0 && j >0)
    {
        if (S1[i-1]==S2[j-1])
        {
            sequence[index-1]=S1[i-1];
            index--;
            i--;
            j--;
        }
        else if (LCS_Table[i-1][j]>LCS_Table[i][j-1] ){
            i--;
        }
        else{
            j--;
        }
        
    }
    printf("\nThe least common subsequence is : %s", sequence);
}
void main(){
    printf("\nEnter the string : ");
    gets(S1);
    printf("\nEnter the second string : ");
    gets(S2);
    LCS();
}