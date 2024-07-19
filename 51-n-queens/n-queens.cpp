#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<vector<char>>board, int row, int col, int n){
        for(int i=0; i<n; i++){
            if(board[row][i]=='Q'){
                return false;
            }
        }
        for(int j=0; j<n;j++){
            if(board[j][col]=='Q'){
                return false;
            }
        }
        for(int r=row, c=col; r>=0 && c>=0; r--, c--){
            if(board[r][c]=='Q'){
                return false;
            }
        }
        for(int r=row, c=col; r<n && c>=0; r++, c--){
            if(board[r][c]=='Q'){
                return false;
            }
        }
        for(int r=row, c=col; r>=0 && c<n; r--, c++){
            if(board[r][c]=='Q'){
                return false;
            }
        }        
        for(int r=row, c=col; r<n && c<n; r++, c++){
            if(board[r][c]=='Q'){
                return false;
            }
        }
        return true;
    }
    void saveBoard(vector<vector<char>>board, vector<vector<string>> &allBoards, int n){
        vector<string>newBoard;
        for(int i=0; i<n; i++){
            string res="";
            for(int j=0; j<n; j++){
                res+=board[i][j];
            }
            newBoard.push_back(res);
        }
        allBoards.push_back(newBoard);
    }
    void helper(vector<vector<char>>board, vector<vector<string>> &allBoards, int col, int n){
        if(col == n){
            saveBoard(board, allBoards, n);
            return;
        }
        for(int row=0; row<n; row++){
            if(canPlace(board, row, col, n)){
                board[row][col]='Q';
                helper(board, allBoards, col+1, n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> allBoards;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        helper(board, allBoards, 0, n);
        return allBoards;
    }
};