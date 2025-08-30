class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.') 
                    continue;
                if (find(rows[i].begin(), rows[i].end(), num) != rows[i].end())
                    return false;
                rows[i].push_back(num);
                if (find(cols[j].begin(), cols[j].end(), num) != cols[j].end())
                    return false;
                cols[j].push_back(num);
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (find(boxes[boxIndex].begin(), boxes[boxIndex].end(), num) != boxes[boxIndex].end())
                    return false;
                boxes[boxIndex].push_back(num);
            }
        }
        return true;
    }
};