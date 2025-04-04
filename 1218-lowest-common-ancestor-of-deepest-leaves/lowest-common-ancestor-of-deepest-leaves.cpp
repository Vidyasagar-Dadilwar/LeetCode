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
 */
class Solution {
public:
    pair<TreeNode*, int> solve(TreeNode* root, int depth){
        if(root == NULL)
            return {root, depth+1};
        auto l = solve(root->left, depth+1);
        auto r = solve(root->right, depth+1);

        if(l.second < r.second)
            return r;
        else if(l.second > r.second)
            return l;
        else
            return {root, l.second};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto it = solve(root, 0);
        return it.first;
    }
};