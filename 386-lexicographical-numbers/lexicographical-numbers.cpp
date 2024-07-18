class Solution {
public:
    void solve(int n, int curr, vector<int>&ans){
        if(curr>n)
            return;
        ans.push_back(curr);
        for(int i=0; i<10; i++){
            if(curr*10 + i >n){
                return;
            }
            solve(n, curr*10+i, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<10; i++){
            if(i>n)
                break;
            solve(n, i, ans);
        }
        return ans;
    }
};