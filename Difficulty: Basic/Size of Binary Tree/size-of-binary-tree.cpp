/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int size = 0;
    void inorder(Node* root){
        if(!root)
            return;
        inorder(root->left);
        size++;
        inorder(root->right);
    }
    int getSize(Node* root) {
        // code here
        inorder(root);
        return size;
    }
};