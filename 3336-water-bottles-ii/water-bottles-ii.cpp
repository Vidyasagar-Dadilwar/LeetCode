class Solution {
public:
    int solve(int n, int k){
        if(n < k)
            return 0;
        return 1+solve(n-k+1, k+1);
    }
    int maxBottlesDrunk(int n, int k) {
        return n+solve(n, k);
    }
};