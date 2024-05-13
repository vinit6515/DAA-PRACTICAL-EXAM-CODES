#include<conio.h>
#include<stdbool.h>
#include<stdio.h>
void printArray(int n , char board[n][n]){

    printf("\n");
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            printf(" %c ",board[i][j]);
        }
        printf("\n");
    }
}
bool isSafe(int n , char board[n][n], int row, int col){
    for(int i =0;i<n;i++){
        if(board[row][i]=='Q'){
        return false;}
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;}
    }
    for(int i =row,j=col;i<n&&j>=0;i++,j--){
        if(board[i][j]=='Q'){
        return false;}
    }
    return true;
}
void NQueen(int n , char board[n][n], int col){
    if(col>=n){
        printArray(n,board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(isSafe(n,board,i,col)){
            board[i][col]='Q';
            NQueen(n,board,col+1);
            board[i][col]='.';
        }
    }
}
void solveNQUEEN(int n){
    char board[n][n];
    for(int i=0;i<n;i++){
        for(int j =0; j < n ;j++){
            board[i][j]='.';
        }
    }
    NQueen(n,board,0);
}
void main(){
    int queen;
    printf("\nEnter number of queens: ");
    scanf("%d",&queen);
    solveNQUEEN(queen);
}
