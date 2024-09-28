#include<bits/stdc++.h>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxi = 0;
        for(int i=0; i<k ;i++){
            maxi += nums[i];
        }
        int curr = maxi;
        for(int i=k; i<nums.size(); i++){
            curr += nums[i] - nums[i-k];
            maxi = max(maxi, curr);
        }
        return (double)maxi/k;
    }
};