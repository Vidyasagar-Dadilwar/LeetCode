class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int i=0, j=0, cnt=0, n=fruits.size();
        vector<int> vis(n, 0);
        while(i<n && j<=n){
            if(j == n){
                i++;
                j=0;
            }
            if(i<n && !vis[j] && fruits[i] <= baskets[j]){
                i++;
                vis[j] = 1;
                j=0;
            }
            else
                j++;
        }
        return n-accumulate(vis.begin(), vis.end(), 0);
    }
};