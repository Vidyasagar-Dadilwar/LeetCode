class Solution {
public:
    pair<int, int> intToPos(int sq, int n){
        int r = (sq - 1) / n, c = (sq - 1) % n;
        if(r%2 != 0)
            c = n - 1 - c; 
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        int n = board.size();
        queue<pair<int, int>> q;
        q.push({1, 0});
        unordered_set<int> vis;

        while(!q.empty()){
            auto it = q.front();
            int sq = it.first, moves = it.second;
            q.pop();

            for(int i=1; i<7; i++){
                int nextSq = sq + i;
                if(nextSq > n*n)    
                    break;
                auto x = intToPos(nextSq, n);
                int r = x.first, c = x.second;
                if(board[r][c] != -1)
                    nextSq = board[r][c];
                if(nextSq == n*n)
                    return moves + 1;
                if(vis.find(nextSq) == vis.end()){
                    vis.insert(nextSq);
                    q.push({nextSq, moves+1});
                }
            }
        }
        return -1;
    }
};