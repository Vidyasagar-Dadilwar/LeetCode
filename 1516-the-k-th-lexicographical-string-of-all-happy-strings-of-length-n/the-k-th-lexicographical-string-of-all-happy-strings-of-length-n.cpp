class Solution {
public:
    void solve(int n, string &curr, vector<string> &ans){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        string abc = "abc";
        for(int i=0; i<3; i++){
            if(curr.empty() || curr.back() != abc[i]){
                curr.push_back(abc[i]);
                solve(n, curr, ans);
                curr.pop_back();
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        string curr;
        vector<string> ans;
        solve(n, curr, ans);
        sort(ans.begin(), ans.end());
        if(ans.size() < k)
            return "";
        return ans[k-1];
    }
};