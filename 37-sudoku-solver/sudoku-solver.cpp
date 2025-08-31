class Solution {
public:
    bool canPlace(int cr, int cc, char i, vector<vector<char>>& board){
        for(int k=0; k<9; k++){
            if(board[cr][k] == i || board[k][cc] == i)
                return false;
        }
        int r = (cr/3)*3, c = (cc/3)*3;
        for(int row=r; row<r+3; row++){
            for(int col=c; col<c+3; col++){
                if(board[row][col] == i)
                    return false;
            }
        }
        return true;
    }
    bool solve(int cr, int cc, vector<vector<char>>& board){
        if(cr == 9)
            return true;
        if(cc == 9)
            return solve(cr+1, 0, board);
        if(board[cr][cc] == '.'){
            for(char i='1'; i<='9'; i++){
                if(canPlace(cr, cc, i, board)){
                    board[cr][cc] = i;
                    if(solve(cr, cc+1, board))  
                        return true;
                    board[cr][cc] = '.';
                }
            }
            return false;
        }
        else
            return solve(cr, cc+1, board);
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};