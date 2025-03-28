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
    public int solve(TreeNode root, int[] dia){
        if(root == null)
            return 0;
        int left = solve(root.left, dia);
        int right = solve(root.right, dia);
        dia[0] = Math.max(dia[0], left+right);
        return 1 + Math.max(left, right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int[] dia = new int[1];
        solve(root, dia);
        return dia[0];
    }
}