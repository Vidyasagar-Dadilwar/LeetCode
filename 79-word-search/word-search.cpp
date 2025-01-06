class Solution {
public:
    // algorithm:
    // 1. for each element of the board call findWord function
    // 2. findWord function
    //     checks the index out of bound
    //     checks valid position of i, j and checks if word at currInd 
    //         equal to board at position i, j and also check if position
    //         i, j are already visited or not
    //     marks the position i, j visited
    //     iteratively calls findWord function for all the 4 direction
    //     returns true if found word in any of the direction
    //     returns vis[i][j] == false;
    // 3. isValid checks if the pos i, j is not out of the bounds


    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, int n, int m){
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    bool findWord(int i, int j, int ind, vector<vector<char>>& board, 
            vector<vector<bool>>& vis, string word){
        if(ind == word.size()){
            return true;
        }
        if(!isValid(i, j, board.size(), board[0].size()) || word[ind] != board[i][j] || vis[i][j]){
            return false;
        }
        vis[i][j] = true;
        for(int k=0; k<4; k++){
            int newi = i + dx[k];
            int newj = j + dy[k];
            bool isPossible = findWord(newi, newj, ind+1, board, vis, word);
            if(isPossible)
                return true;
        }
        return vis[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();        
        vector<vector<bool>> vis(n, vector<bool>(m));        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (findWord(i, j, 0, board, vis, word)) 
                    return true;
            }
        }        
        return false;
    }
};