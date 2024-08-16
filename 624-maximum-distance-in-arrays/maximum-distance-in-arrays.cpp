class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = INT_MAX, second_min_val = INT_MAX;
        int max_val = INT_MIN, second_max_val = INT_MIN;
        int min_idx = -1, max_idx = -1;

        for (int i = 0; i < arrays.size(); ++i) {
            int curr_min = arrays[i].front();
            int curr_max = arrays[i].back();

            if (curr_min < min_val) {
                second_min_val = min_val;
                min_val = curr_min;
                min_idx = i;
            } else if (curr_min < second_min_val) {
                second_min_val = curr_min;
            }

            if (curr_max > max_val) {
                second_max_val = max_val;
                max_val = curr_max;
                max_idx = i;
            } else if (curr_max > second_max_val) {
                second_max_val = curr_max;
            }
        }

        if (min_idx != max_idx) {
            return max_val - min_val;
        }
        
        return max(max_val - second_min_val, second_max_val - min_val);
    }
};