class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int prevColor){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != prevColor)
            return;
        
        image[sr][sc] = color;
        for(auto it: dirs){
            int nsr = sr + it.first, nsc = sc + it.second;
            dfs(image, nsr, nsc, color, prevColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor = image[sr][sc];
        if(prevColor != color)
            dfs(image, sr, sc, color, prevColor);
        return image;
    }
};