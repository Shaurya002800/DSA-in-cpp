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



 class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        while(N > 0) {
            if(N % 2 == 1) {
                ans *= x;
            }
            x *= x;
            N /= 2;
        }
        return ans;
    }
}
