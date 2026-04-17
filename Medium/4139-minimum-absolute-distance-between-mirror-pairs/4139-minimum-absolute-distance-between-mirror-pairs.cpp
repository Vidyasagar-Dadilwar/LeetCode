class Solution {
public:
    int reverse(int n){
        int tmp = 0;
        while(n!=0){
            int t = n%10;
            tmp = tmp*10 + t;
            n = n/10;
        }
        return tmp;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(mp.contains(nums[i])){
                ans = min(ans, abs(i-mp[nums[i]]));
            }
            int tmp = reverse(nums[i]);
            mp[tmp] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};