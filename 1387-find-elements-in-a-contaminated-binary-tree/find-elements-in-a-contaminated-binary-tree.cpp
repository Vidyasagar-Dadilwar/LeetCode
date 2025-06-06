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
class FindElements {
public:
    unordered_set<int> recoveredValues;
    FindElements(TreeNode* root) {
        solve(root, 0);
    }
    
    void solve(TreeNode* node, int value) {
        if (!node) 
            return;
        node->val = value; 
        recoveredValues.insert(value); 
        solve(node->left, 2 * value + 1); 
        solve(node->right, 2 * value + 2); 
    }

    bool find(int target) {
        return recoveredValues.find(target) != recoveredValues.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */