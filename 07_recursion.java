import java.util.*;
//STRING TO INTEGER

// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
// The algorithm for myAtoi(string s) is as follows:
// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.

 

// Example 1:
// Input: s = "42"
// Output: 42
// Explanation:

// The underlined characters are what is read in and the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "42" ("42" is read in)


// class Solution {
//     public int myAtoi(String s) {
//         int i = 0;
//         int n = s.length();
//         // 1. Skip leading spaces
//         while(i < n && s.charAt(i) == ' ') {
//             i++;
//         }
//         // 2. Check sign
//         int sign = 1;
//         if(i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
//             if(s.charAt(i) == '-') {
//                 sign = -1;
//             }
//             i++;
//         }
//         // 3. Build number
//         long num = 0;
//         while(i < n && Character.isDigit(s.charAt(i))) {
//             num = num * 10 + (s.charAt(i) - '0');
//             // 4. Handle overflow
//             if(sign * num > Integer.MAX_VALUE) {
//                 return Integer.MAX_VALUE;
//             }
//             if(sign * num < Integer.MIN_VALUE) {
//                 return Integer.MIN_VALUE;
//             }
//             i++;
//         }
//         return (int)(sign * num);
//     }
// }











//POW Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25



//  class Solution {
//     public double myPow(double x, int n) {
//         long N = n;
//         if(N < 0) {
//             x = 1 / x;
//             N = -N;
//         }
//         double ans = 1;
//         while(N > 0) {
//             if(N % 2 == 1) {
//                 ans *= x;
//             }
//             x *= x;
//             N /= 2;
//         }
//         return ans;
//     }
// }

















//COUNT GOOD NuMBERS

// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".



// class Solution {
//     long MOD = 1000000007;
//     public int countGoodNumbers(long n) {
//         long even = (n + 1) / 2;
//         long odd = n / 2;
//         long ans = (power(5, even) * power(4, odd)) % MOD;
//         return (int)ans;
//     }
//     public long power(long x, long n) {
//         long ans = 1;
//         while(n > 0) {
//             if((n & 1) == 1) {
//                 ans = (ans * x) % MOD;
//             }
//             x = (x * x) % MOD;
//             n >>= 1;
//         }
//         return ans;
//     }
// }
















//GENERTE PARENTHESES

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]


// class Solution {
//     public List<String> generateParenthesis(int n) {
//         List<String> result = new ArrayList<>();
//         backtrack(new StringBuilder(), result, 0, 0, n);
//         return result;
//     }

//     private void backtrack(StringBuilder current, List<String> result, int open, int close, int n) {
//         if (current.length() == (2 * n)) {
//             result.add(current.toString());
//             return;
//         }
//         if (open < n) {
//             current.append('(');
//             backtrack(current, result, open + 1, close, n);
//             current.deleteCharAt(current.length() - 1);
//         }
//         if (close < open) {
//             current.append(')');
//             backtrack(current, result, open, close + 1, n);
//             current.deleteCharAt(current.length() - 1);
//         }
//     }
// }














//COMBINATION SUM

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input. 

// Example 1:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// class Solution {
//     List<List<Integer>> see = new ArrayList<>();
//     public List<List<Integer>> combinationSum(int[] candidates, int target) {
//         List<Integer> curr = new ArrayList<>();
//         Arrays.sort(candidates);
//         solve(candidates, target, 0, curr);
//         return see;
//     }
//     public void solve(int[] arr, int target, int st, List<Integer> curr){
//         if(target == 0){
//             see.add(new ArrayList(curr));
//             return;
//         }
//         for(int i = st; i < arr.length; i++){
//             if(arr[i] > target) break;
//             curr.add(arr[i]);
//             solve(arr, target - arr[i], i, curr);
//             curr.remove(curr.size() - 1);
//         }
//     }
// }















//SUBSETS 


// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]



// class Solution {
//     List<List<Integer>> see = new ArrayList<>();
//     public List<List<Integer>> subsetsWithDup(int[] nums) {
//         List<Integer> curr = new ArrayList<>();
//         Arrays.sort(nums);
//         solve(nums, 0, curr);
//         return see;
//     }
//     public void solve(int[] arr, int st, List<Integer> curr){
//         see.add(new ArrayList<>(curr));
        
//         for(int i = st; i < arr.length; i++){
//             if(i > st && arr[i] == arr[i - 1]) continue;
//             curr.add(arr[i]);
//             solve(arr, i + 1, curr);
//             curr.remove(curr.size() - 1);
//         }
//     }
// }
















//LETTER COMBINATIONS OF A PHONE NUMBER

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]


class Solution {
    List<String> see = new ArrayList<>();
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) return see;
        char[][] temp = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        solve(temp, 0, digits, "");
        return see;
    }
    public void solve(char[][] arr, int st, String digits, String he) {
        if(he.length() == digits.length()) {
            see.add(he);
            return;
        }
        int idx = digits.charAt(st) - '2';
        for(int i = 0; i < arr[idx].length; i++) {
            solve(
                arr,
                st + 1,
                digits,
                he + arr[idx][i]
            );
        }
    }
}