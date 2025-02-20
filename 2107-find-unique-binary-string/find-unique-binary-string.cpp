class Solution {
public:
    string res;
    void solve(string &curr, int n, vector<string>& nums){
        if(curr.size() == n){
            if(find(nums.begin(), nums.end(), curr) == nums.end()){
                res = curr;
            }
            return;
        }
        string tmp = "01";
        for(int i=0; i<2; i++){
            curr.push_back(tmp[i]);
            solve(curr, n, nums);
            curr.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string curr;
        int n = nums.size();
        solve(curr, n, nums);
        return res;
    }
};