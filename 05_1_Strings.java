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


class Solution {
    public String longestCommonPrefix(String[] strs) {
        // take first string as initial prefix
        String prefix = strs[0];
        for(int i = 1; i < strs.length; i++) {
            // keep reducing prefix until it matches
            while(strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
                // if nothing left
                if(prefix.isEmpty()) {
                    return "";
                }
            }
        }

        return prefix;
    }
}