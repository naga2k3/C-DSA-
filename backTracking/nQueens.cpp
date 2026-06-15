#include <bits/stdc++.h>
using namespace std;
void printBoard(vector<vector<char>> board){
    int n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------\n";
}
bool isSafe(vector<vector<char>> board , int row , int col){
    int n = board.size();
    for(int i=0;i<n;i++){
        if(board[row][i] == 'Q') return false;
    }
    for(int j=0;j<row;j++){
        if(board[j][col] == 'Q') return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j] == 'Q') return false;
    }
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j] == 'Q') return false;
    }
    return true;
}
int nQueen(vector<vector<char>> board , int row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return 1;
    }
    int count =0;
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j)){
            board[row][j] = 'Q';
            count += nQueen(board,row+1);
            board[row][j] = '.';
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>board;
    for(int i=0;i<n;i++){
        vector<char>newRow;
        for(int j=0;j<n;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    int count = nQueen(board,0);
    cout<<count;
    return 0;
}