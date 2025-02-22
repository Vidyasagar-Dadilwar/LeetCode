/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

 "1-2--3--4-5--6--7"
 */
class Solution {
public:
    string s;
    int ind = 0, level = 0;
    void solve(TreeNode* ans, int lvl){
        while(ind<s.size() && lvl==level){
            int n = 0;
            while(ind<s.size() && isdigit(s[ind])){
                n = n*10 + (s[ind]-'0');
                ind++;
            }
            TreeNode* t = new TreeNode(n);
            if(!ans->left)
                ans->left = t;
            else
                ans->right = t;
            level = 0;
            while(ind<s.size() && s[ind] == '-'){
                level++;
                ind++;
            }
            solve(t, lvl +1);
        }
    }
    TreeNode* recoverFromPreorder(string traversal) {
        s = traversal;
        TreeNode* ans = new TreeNode(-1);
        solve(ans, 0);
        return ans->left;
    }
};