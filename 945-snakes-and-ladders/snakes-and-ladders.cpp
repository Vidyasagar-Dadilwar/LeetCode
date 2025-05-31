class Solution {
public:
    pair<int, int>intToPos(int sq, int n){
        int r = (sq-1)/n, c = (sq-1)%n;
        if(r%2 != 0)
            c = n-1-c;
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        reverse(board.begin(), board.end());
        queue<pair<int, int>> q;
        q.push({1, 0});
        unordered_set<int> vis;

        while(!q.empty()){
            auto [sq, moves] = q.front();
            q.pop();
            
            for(int i=1; i<7; i++){
                int nextSq = sq + i;
                if(nextSq > n*n)
                    break;
                auto [r, c] = intToPos(nextSq, n);

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