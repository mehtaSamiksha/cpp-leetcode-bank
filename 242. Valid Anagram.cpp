// Problem: 242. Valid Anagram
// Difficulty: Easy
// Topic: Hashing, Strings
// Link: https://leetcode.com/problems/valid-anagram
// Approach: Count characters in both strings and compare frequency
// Time Complexity: O(n)
// Space Complexity: O(1) — constant for 26 lowercase letters

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> count(26);

        for (const char c : s)
            ++count[c - 'a'];

        for (const char c : t) {
            if (count[c - 'a'] == 0)
                return false;
            --count[c - 'a'];
        }

        return true;
    }
};
