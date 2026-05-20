// Remove Outermost Parentheses

// Example 2:

// Input: s = "(()())(())(()(()))"
// Output: "()()()()(())"
// Explanation: 
// The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
// After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

// class Solution {
//     public String removeOuterParentheses(String s) {
//         StringBuilder sb = new StringBuilder();
//         int open = 0;
//         for(char ch : s.toCharArray()) {
//             if(ch == '(') {
//                 if(open > 0) {
//                     sb.append(ch);
//                 }
//                 open++;
//             }
//             else {
//                 open--;
//                 if(open > 0) {
//                     sb.append(ch);
//                 }
//             }
//         }
//         return sb.toString();
//     }
// }






// --------------------------------------------------------------------------







// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"


// class Solution {
//     public String longestCommonPrefix(String[] strs) {
//         // take first string as initial prefix
//         String prefix = strs[0];
//         for(int i = 1; i < strs.length; i++) {
//             // keep reducing prefix until it matches
//             while(strs[i].indexOf(prefix) != 0) {
//                 prefix = prefix.substring(0, prefix.length() - 1);
//                 // if nothing left
//                 if(prefix.isEmpty()) {
//                     return "";
//                 }
//             }
//         }

//         return prefix;
//     }
// }







// ------------------------------------------------








// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"

// Output: true

// Explanation:

// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.

class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] sToT = new int[256];
        int[] tToS = new int[256];
        for (int i = 0; i < s.length(); i++) {
            char sChar = s.charAt(i);
            char tChar = t.charAt(i);
            if (sToT[sChar] != tToS[tChar]) return false;
            sToT[sChar] = i + 1;
            tToS[tChar] = i + 1;

        }
        return true;
    }
}