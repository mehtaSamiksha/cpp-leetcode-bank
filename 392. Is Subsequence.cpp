// Problem: 392. Is Subsequence
// Difficulty: Easy
// Topic: Two Pointers, String
// Link: https://leetcode.com/problems/is-subsequence
// Approach: Use a pointer to track matching characters in s while iterating over t
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())
            return true;

        int i = 0;
        for (const char c : t)
            if (s[i] == c && ++i == s.length())
                return true;

        return false;
    }
};
