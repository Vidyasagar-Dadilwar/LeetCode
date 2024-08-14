class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min_dist = 0, max_dist = nums.back() - nums.front();
        int l = min_dist, h = max_dist;
        while(l!=h){
            auto e = nums.end();
            auto mid = l+(h-l)/2;
            int x = -nums.size();
            for(auto i = nums.begin(); x<k && i!=e; i++){
                // last pair jaha tk dist less than mid rhega uska aur 
                // current pos ka difference defines possible pairs 
                x += upper_bound(i, e, (*i)+mid) - i;
            }
            if(x<k){
                l = mid+1;
            }
            else{
                h = mid;
            }
        }
        return l;
    }
};