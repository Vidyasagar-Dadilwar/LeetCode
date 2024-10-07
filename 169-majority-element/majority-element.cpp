class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int votes = 0, el;
        for(auto i: nums){
            if(votes == 0){
                el = i;
                votes = 1;
            }
            else if(i == el){
                votes++;
            }
            else{
                votes--;
            }
        }
        int cnt=0;
        for(auto i: nums){
            if(i == el)
                cnt++;
        }
        if(cnt > nums.size()/2)
            return el;
        else
            return -1;
    }
};