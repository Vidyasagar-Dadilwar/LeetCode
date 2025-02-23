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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        int n = preorder.size();
        vector<int> it(n+1);

        for(int i=0; i<n; i++)
            it[postorder[i]] = i;

        for(int i=1; i<n; i++){
            while(st.size() && it[preorder[i]] > it[st.top()->val])
                st.pop();

            TreeNode* tmp = st
            .top();
            TreeNode* node = new TreeNode(preorder[i]);
            if(!tmp->left)  
                tmp->left = node;
            else
                tmp->right = node;
            st.push(node);
        }
        return root;
    }
};