// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.




// class Solution {
//     public String frequencySort(String s) {
//         char[] str = s.toCharArray();
//         int[] freq = new int[128];
//         for (int i = 0; i < str.length; i++) {
//             freq[str[i]]++;
//         }
//         for (int i = 0; i < str.length;) {
//             int maxFreq = 0;
//             char cmax = 0;
//             for (int j = 0; j < 128; j++) {
//                 if (freq[j] > maxFreq) {
//                     maxFreq = freq[j];
//                     cmax = (char) j;
//                 }
//             }
//             while (freq[cmax] != 0) {
//                 str[i++] = cmax;
//                 freq[cmax]--;
//             }
//         }
//         return new String(str);
//     }
// }










// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.





// class Solution {
//     public int romanToInt(String s) {
//         int ans = 0;
//         for(int i = 0; i < s.length(); i++) {
//             int curr = value(s.charAt(i));
//             if(i < s.length() - 1 &&
//                curr < value(s.charAt(i + 1))) {
//                 ans -= curr;
//             }
//             else {
//                 ans += curr;
//             }
//         }
//         return ans;
//     }
//     public int value(char ch) {
//         if(ch == 'I') return 1;
//         if(ch == 'V') return 5;
//         if(ch == 'X') return 10;
//         if(ch == 'L') return 50;
//         if(ch == 'C') return 100;
//         if(ch == 'D') return 500;
//         return 1000;
//     }
// }










// String to Integer

// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.



class Solution {
    public int myAtoi(String s) {
        int i = 0;
        int n = s.length();
        // 1. Skip leading spaces
        while(i < n && s.charAt(i) == ' ') {
            i++;
        }
        // 2. Check sign
        int sign = 1;
        if(i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            if(s.charAt(i) == '-') {
                sign = -1;
            }
            i++;
        }
        // 3. Build number
        long num = 0;
        while(i < n && Character.isDigit(s.charAt(i))) {
            num = num * 10 + (s.charAt(i) - '0');
            // 4. Handle overflow
            if(sign * num > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if(sign * num < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
            i++;
        }
        return (int)(sign * num);
    }
}