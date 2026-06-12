import java.util.*;
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
   TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
 





// BINARY TREE POSTORDER TRAVERSAL

// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [3,2,1]


class Solution {
    List<Integer> see = new ArrayList<>();
    public List<Integer> postorderTraversal(TreeNode root) {
        solve(root);
        return see;
    }
    public void solve(TreeNode root){
        if(root == null) return;
        solve(root.left);
        solve(root.right);
        see.add(root.val);
    }
}