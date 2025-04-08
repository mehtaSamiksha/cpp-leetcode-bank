// Problem: 205. Isomorphic Strings
// Difficulty: Easy
// Topic: Hashing, Strings
// Link: https://leetcode.com/problems/isomorphic-strings
// Approach: Use two hash maps (arrays) to ensure one-to-one character mapping
// Time Complexity: O(n)
// Space Complexity: O(1) — constant for ASCII character mapping

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map1[256] = {}, map2[256] = {};
        for (int i = 0; i < s.size(); ++i) {
            if (map1[s[i]] != map2[t[i]])
                return false;
            map1[s[i]] = map2[t[i]] = i + 1;
        }
        return true;
    }
};
