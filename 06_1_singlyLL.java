class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}



// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. You will not be given access to the first node of head.

// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.
// Custom testing:

// For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
// We will build the linked list and pass the node to your function.
// The output will be the entire list after calling your function.
 

// Example 1:


// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.



/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// class Solution {
//     public void deleteNode(ListNode node) {
//         node.val = node.next.val;
//         node.next = node.next.next;
//     }
// }




//REVERSE THE LINK LIST
// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []



//MY SOLUTION
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// import java.util.*;
// class Solution {
//     public ListNode reverseList(ListNode head) {
//         ListNode temp = head;
//         ListNode see = head;
//         Vector<Integer> yo = new Vector<>();
//         int i = 0;
//         while(temp != null){
//             yo.add(temp.val);
//             i++;
//             temp = temp.next;
//         }
//         // Collections.reverse(yo);
//         while(i > 0){
//             i--;
//             see.val = yo.get(i);
//             see = see.next;
//         }
//         see = head;
//         return see;
//     }
// }


// OPTIMIZED

/**
 * Definition for singly-linked list.
 */

// class Solution {
//     public ListNode reverseList(ListNode head) {
        
//         ListNode prev = null;
//         ListNode curr = head;

//         while (curr != null) {
//             ListNode nextTemp = curr.next; // store next node
//             curr.next = prev;              // reverse link
//             prev = curr;                   // move prev
//             curr = nextTemp;               // move curr
//         }

//         return prev;
//     }

// }










// given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

 
// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).


// Floyd Cycle Detection Algorithm

// Also called:

// Tortoise and Hare Algorithm


// public class 06_1_singlyLL {
//     public boolean hasCycle(ListNode head) {
//         ListNode slow = head;
//         ListNode fast = head;
//         while(fast != null && fast.next != null) {
//             slow = slow.next;
//             fast = fast.next.next;
//             // cycle detected
//             if(slow == fast) {
//                 return true;
//             }
//         }
//         return false;
//     }
// }







//PALINDROME LINKED LIST
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.


// Example 1:
// Input: head = [1,2,2,1]
// Output: true


class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null){
            return true;
        }
        ListNode slow = head;
        ListNode fast = head;
        // Find middle
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        // Reverse second half
        ListNode prev = null;
        ListNode curr = slow;
        while(curr != null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        // Compare both halves
        ListNode first = head;
        ListNode second = prev;
        while(second != null){
            if(first.val != second.val){
                return false;
            }
            first = first.next;
            second = second.next;
        }
        return true;
    }
}
