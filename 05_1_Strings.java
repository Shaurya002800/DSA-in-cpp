// Remove Outermost Parentheses

// Example 2:

// Input: s = "(()())(())(()(()))"
// Output: "()()()()(())"
// Explanation: 
// The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
// After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder sb = new StringBuilder();
        int open = 0;
        for(char ch : s.toCharArray()) {
            if(ch == '(') {
                if(open > 0) {
                    sb.append(ch);
                }
                open++;
            }
            else {
                open--;
                if(open > 0) {
                    sb.append(ch);
                }
            }
        }
        return sb.toString();
    }
}