// Problem: 38. Count and Say
// Difficulty: Medium
// Topic: Recursion, String
// Link: https://leetcode.com/problems/count-and-say
// Approach: Use recursion to build the sequence and compress digits using run-length encoding
// Time Complexity: O(n * m) where m is the average length of each sequence
// Space Complexity: O(m) for each recursion stack and result string

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1), res = "";
        for (int i = 0; i < prev.size(); ) {
            int count = 1;
            while (i + count < prev.size() && prev[i] == prev[i + count]) ++count;
            res += to_string(count) + prev[i];
            i += count;
        }
        return res;
    }
};
