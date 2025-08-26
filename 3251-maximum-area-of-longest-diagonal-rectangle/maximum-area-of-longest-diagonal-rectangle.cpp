class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0;
        int maxArea = 0;
        for(int i = 0; i < dimensions.size(); i++){
            int a = dimensions[i][0], b = dimensions[i][1];
            double diagonal = sqrt(1.0 * a * a + 1.0 * b * b);
            int area = a * b;

            if(diagonal > maxDiagonal){
                maxDiagonal = diagonal;
                maxArea = area;
            } 
            else if(fabs(diagonal - maxDiagonal) < 1e-9){ 
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};