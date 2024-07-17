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
    void solve(TreeNode* curr, set<int>&s,vector<TreeNode*>& ans){
        if(curr->left != NULL){
            solve(curr->left, s, ans);
        }
        if(curr->right != NULL){
            solve(curr->right, s, ans);
        }
        if(curr->left != NULL){
            if(s.find(curr->left->val) != s.end()){
                curr->left = NULL;
            }
        }
        if(curr->right != NULL){
            if(s.find(curr->right->val) != s.end()){
                curr->right = NULL;
            }
        }
        if(s.find(curr->val) != s.end()){
            if(curr->left != NULL){
                ans.push_back(curr->left);
            }
            if(curr->right != NULL){
                ans.push_back(curr->right);
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        set<int>s(to_delete.begin(), to_delete.end());
        if(s.find(root->val)==s.end()){
            ans.push_back(root);
        }
        solve(root, s, ans);
        return ans;
    }
};