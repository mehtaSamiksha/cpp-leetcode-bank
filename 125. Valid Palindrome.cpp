// Problem: 125. Valid Palindrome
// Difficulty: Easy
// Topic: Two Pointers, String
// Link: https://leetcode.com/problems/valid-palindrome
// Approach: Use two pointers to compare alphanumeric characters case-insensitively
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l]))
                ++l;
            while (l < r && !isalnum(s[r]))
                --r;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            ++l;
            --r;
        }

        return true;
    }
};
