class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(all_of(nums.begin(), nums.end(), [](int num){return num==0;})){
            return "0";
        }
        vector<string>stringNum;
        for(auto i: nums)
            stringNum.push_back(to_string(i));
        sort(stringNum.begin(), stringNum.end(), [](const string &a, const string &b){
            return a+b>b+a;
        });
        string ans;
        for(auto i: stringNum)
            ans += i;
        return ans;
    }
};