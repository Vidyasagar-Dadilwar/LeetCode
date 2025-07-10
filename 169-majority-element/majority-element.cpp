class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote=0, el;
        for(auto it: nums){
            if(vote == 0){
                el = it;
                vote++;
            }
            else if(it == el) vote++;
            else if(it != el) vote--;
        }
        vote = 0;
        for(auto it: nums){
            if(it == el) vote++;
        }
        return (vote > nums.size()/2) ? el : -1;
    }
};