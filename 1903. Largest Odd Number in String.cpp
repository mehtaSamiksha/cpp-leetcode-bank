// Problem: 1903. Largest Odd Number in String
// Difficulty: Easy
// Topic: String, Greedy
// Link: https://leetcode.com/problems/largest-odd-number-in-string
// Approach: Traverse from the end and return the longest prefix ending with an odd digit
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            if (num[i] % 2 == 1)
                return num.substr(0, i + 1);
        }
        return "";
    }
};
