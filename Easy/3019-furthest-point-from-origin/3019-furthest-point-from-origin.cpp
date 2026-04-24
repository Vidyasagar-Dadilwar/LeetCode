class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0, blanks = 0;
        for(auto it: moves){
            if(it == 'L') ans++;
            else if(it == 'R')  ans--;
            else blanks++;
        }
        return abs(ans)+blanks;
    }
};