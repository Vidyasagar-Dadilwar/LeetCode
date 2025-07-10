class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int one=0,maxOne=0;
        for(int i:nums){
            if(i==1)
                maxOne=max(maxOne,++one);
            else
                one=0;
        }
        return maxOne;
    }
};