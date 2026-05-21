// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.




class Solution {
    public String frequencySort(String s) {
        // Convert input string to character array
        char[] str = s.toCharArray();
        // Create an array to store frequency of each character
        int[] freq = new int[128];
        // Count the frequency of each character in the input string
        for (int i = 0; i < str.length; i++) {
            freq[str[i]]++;
        }
        // Sort the characters based on their frequency
        for (int i = 0; i < str.length;) {
            int maxFreq = 0;
            char cmax = 0;
            // Find the character with the maximum frequency
            for (int j = 0; j < 128; j++) {
                if (freq[j] > maxFreq) {
                    maxFreq = freq[j];
                    cmax = (char) j;
                }
            }
            // Append the characters to the result string based on their frequency
            while (freq[cmax] != 0) {
                str[i++] = cmax;
                freq[cmax]--;
            }
        }
        // Convert the character array back to a string and return it
        return new String(str);
    }
}