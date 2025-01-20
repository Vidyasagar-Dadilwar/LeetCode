/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode solve(TreeNode root){
        if(root==null)
            return null;
        TreeNode lf = solve(root.left);
        TreeNode rt = solve(root.right);
        root.left = rt;
        root.right = lf;
        return root;
    }
    public TreeNode invertTree(TreeNode root) {
        return solve(root);
    }
}