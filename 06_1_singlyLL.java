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


// class Solution {
//     public boolean isPalindrome(ListNode head) {
//         if(head == null || head.next == null){
//             return true;
//         }
//         ListNode slow = head;
//         ListNode fast = head;
//         // Find middle
//         while(fast != null && fast.next != null){
//             slow = slow.next;
//             fast = fast.next.next;
//         }
//         // Reverse second half
//         ListNode prev = null;
//         ListNode curr = slow;
//         while(curr != null){
//             ListNode next = curr.next;
//             curr.next = prev;
//             prev = curr;
//             curr = next;
//         }
//         // Compare both halves
//         ListNode first = head;
//         ListNode second = prev;
//         while(second != null){
//             if(first.val != second.val){
//                 return false;
//             }
//             first = first.next;
//             second = second.next;
//         }
//         return true;
//     }
// }














//odd even linked list

// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.


// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]


// class Solution {
//     public ListNode oddEvenList(ListNode head) {
//         if(head == null || head.next == null){
//             return head;
//         }
//         ListNode odd = head;
//         ListNode even = head.next;
//         ListNode evenHead = even;
//         while(even != null && even.next != null){
//             odd.next = even.next;
//             odd = odd.next;
//             even.next = odd.next;
//             even = even.next;
//         }
//         odd.next = evenHead;
//         return head;
//     }
// }







//Delete the middle node of a linked list.

// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 
// Example 1:
// Input: head = [1,3,4,7,1,2,6]
// Output: [1,3,4,1,2,6]
// Explanation:
// The above figure represents the given linked list. The indices of the nodes are written below.
// Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
// We return the new list after removing this node. 



// class Solution {
//     public ListNode deleteMiddle(ListNode head) {
//         if(head == null || head.next == null) {
//             return null;
//         }
//         ListNode slow = head;
//         ListNode fast = head;
//         ListNode prev = null;
//         while(fast != null && fast.next != null) {
//             prev = slow;
//             slow = slow.next;
//             fast = fast.next.next;
//         }
//         prev.next = slow.next;
//         return head;
//     }
// }















//SORT LIST

// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]



class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        // Find middle
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode mid = slow.next;
        slow.next = null;
        // Sort left and right halves
        ListNode left = sortList(head);
        ListNode right = sortList(mid);
        // Merge sorted halves
        return merge(left, right);
    }
    public ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while(l1 != null && l2 != null) {
            if(l1.val <= l2.val) {
                tail.next = l1;
                l1 = l1.next;
            }
            else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
        if(l1 != null) {
            tail.next = l1;
        }
        if(l2 != null) {
            tail.next = l2;
        }
        return dummy.next;
    }
}