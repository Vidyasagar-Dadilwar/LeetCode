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
    int max(int a,int b){
        return (a>b)?a:b;
    }
    int height(struct TreeNode* root, int* diameter) {
        if (root == NULL) {
            return 0;
        } 
        else {
            int left = height(root->left, diameter);
            int right = height(root->right, diameter);
            *diameter = max(*diameter, left + right);
            return 1 + max(left, right);
        }
    }
    int diameterOfBinaryTree(struct TreeNode* root) {
        int diameter = 0;
        height(root, &diameter);
        return diameter;
    }
};