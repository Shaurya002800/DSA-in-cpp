import java.util.*;
class Solution {
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


//     List<Integer> see = new ArrayList<>();
//     public List<Integer> postorderTraversal(TreeNode root) {
//         solve(root);
//         return see;
//     }
//     public void solve(TreeNode root){
//         if(root == null) return;
//         solve(root.left);
//         solve(root.right);
//         see.add(root.val);
//     }









//BT LEVEL ORDER TRAVERSAL

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]


//     public List<List<Integer>> levelOrder(TreeNode root) {
//         List<List<Integer>> result = new ArrayList<>();
//         if (root == null) return result;

//         Queue<TreeNode> q = new LinkedList<>();
//         q.offer(root);

//         while (!q.isEmpty()) {
//             int size = q.size();          // ← nodes at current level
//             List<Integer> level = new ArrayList<>();

//             for (int i = 0; i < size; i++) {
//                 TreeNode node = q.poll();
//                 level.add(node.val);
//                 if (node.left  != null) q.offer(node.left);
//                 if (node.right != null) q.offer(node.right);
//             }
//             result.add(level);
//         }
//         return result;
//     }







//Iterative Preorder Traversal 
    // public List<Integer> preorderTraversal(TreeNode root) {
    //     List<Integer> preorder = new ArrayList<Integer>();
    //     if(root == null) return preorder;
    //     Stack<TreeNode> st = new Stack<TreeNode>();
    //     st.push(root);
    //     while(!st.isEmpty()){
    //         root = st.pop();
    //         preorder.add(root.val);
    //         if(root.right != null){
    //             st.push(root.right);
    //         }
    //         if(root.left != null){
    //             st.push(root.left);
    //         }
    //     }
    //     return preorder;
    // }












    //MAXIMUM DEPTH OF BINARY TREE

//     Given the root of a binary tree, return its maximum depth.
//     A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
        public int maxDepth(TreeNode root) {
            if(root == null) {
                return 0;
            }

            int left = maxDepth(root.left);
            int right = maxDepth(root.right);

            return 1 + Math.max(left, right);
        }
}
