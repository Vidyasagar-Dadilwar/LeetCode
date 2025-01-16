class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        bool odd1 = nums1.size()%2, odd2 = nums2.size()%2;
        if(!odd1 && !odd2)
            return 0;
        int res = 0;
        if(odd1){
            for(auto i: nums2)
                res ^= i;
        }
        if(odd2){
            for(auto i: nums1)
                res ^= i;
        }
        return res;
    }
}; 