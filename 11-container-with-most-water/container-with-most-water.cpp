class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, l = 0, r = height.size() - 1;
        while(l < r){
            int h = min(height[l], height[r]);
            maxArea = max(maxArea, h*(r-l));
            if(height[l] <= height[r])
                l++;
            else 
                r--;
        }
        return maxArea;
    }
};