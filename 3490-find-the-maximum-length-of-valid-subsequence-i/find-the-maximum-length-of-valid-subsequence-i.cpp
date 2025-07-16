class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int c = nums[0]%2, o = 0, e = 0, b = 0;
        for(auto it: nums){
            if(it%2 == 0)
                e++;
            else
                o++;
            if(it%2 == c){
                b++;
                c = (c+1)%2;
            }
        }
        return max({o, e, b});
    }
};