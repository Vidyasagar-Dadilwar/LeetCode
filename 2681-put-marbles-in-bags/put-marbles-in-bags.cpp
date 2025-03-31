class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> grt;
        priority_queue<int, vector<int>, greater<int>> less;
        for(int i=0; i<weights.size()-1; i++){
            less.push((weights[i] + weights[i+1]));
            grt.push(weights[i] + weights[i+1]);
        }
        long long ans = 0;
        for(int i=1; i<k; i++){
            ans -= less.top();
            less.pop();
            ans += grt.top();
            grt.pop();
        }
        return ans;
    }
};