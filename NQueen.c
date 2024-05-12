
#include<stdbool.h>
#include<stdio.h>

void printArray(int n , char board[n][n]);
bool isSafe(int n, char board[n][n], int row, int col) {
    // Check the row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void NQueen( int n , char board[n][n], int col){
int i , j;
if(col>=n){
printArray(n,board);
return;
}
for(i=0;i<n;i++){
if(isSafe(n,board,i,col)){

board[i][col]='Q';
NQueen(n,board,col+1);
board[i][col]='.';
}
}
}
void SolveNQueen(int n){
char board[n][n];
int i , j;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
board[i][j]='.';
}
}
NQueen(n,board,0);
}
void main(){
int n ;

printf("\nEnter the number of queens : ");
scanf("%d",&n);
SolveNQueen(n);
}
void printArray(int n , char board[n][n]){
    printf("\n");
int i ,j ;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf(" %c ",board[i][j]);
}
printf("\n");
}
}