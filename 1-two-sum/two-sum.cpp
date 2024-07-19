#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int n = nums.size();
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[i] + nums[j] == target) {
        //             return {i, j};
        //         }
        //     }
        // }


        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            int x=target-nums[i];
            if(mp.find(x)==mp.end()){
                mp[nums[i]]=i;
            }
            else{
                return {mp[x], i};
            }
        }
        return {};
    }
};