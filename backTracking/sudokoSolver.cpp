#include <bits/stdc++.h>
using namespace std;
void printSudoko(int sudoko[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoko[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int sudoko[9][9], int row , int col,int digit){
    for(int i=0;i<9;i++){
        if(sudoko[i][col] == digit) return false;
    }
    for(int i=0;i<9;i++){
        if(sudoko[row][i] == digit) return false;
    }
    int rowSt = (row/3) * 3;
    int colSt = (col/3) * 3;
    for(int i=rowSt;i<rowSt+3;i++){
        for(int j=colSt;j<colSt+3;j++){
            if(sudoko[i][j] == digit) return false;
        }
    }
    return true;
}
bool solve(int sudoko[9][9], int row , int col){
    if(row == 9){
        printSudoko(sudoko);
        return true;
    }
    int nextRow = row;
    int nextCol = col+1;
    if(col+1 == 9){
        nextRow = row+1;
        nextCol = 0;
    }
    if(sudoko[row][col] != 0){
        return solve(sudoko, nextRow , nextCol);      
    }
    for(int digit=1;digit<10;digit++){
        if(isSafe(sudoko,row,col,digit)){
            sudoko[row][col] = digit;
            if(solve(sudoko, nextRow , nextCol)){
                return true;
            }
            sudoko[row][col] = 0;
        }
    }
    return false;
}
int main(){
int sudoko[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};
    solve(sudoko,0,0);
}