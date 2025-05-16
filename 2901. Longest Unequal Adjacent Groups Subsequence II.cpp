// Problem: 2901. Longest Unequal Adjacent Groups Subsequence II
// Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/
// Tags: Dynamic Programming, Hamming Distance, Subsequence, String
// Time Complexity: O(n^2 * m), where n = number of words, m = word length
// Space Complexity: O(n)
// Description:
//   - Find the longest subsequence of words such that each adjacent pair:
//     1. Belongs to different groups.
//     2. Has a Hamming distance of exactly 1 (i.e., exactly one character is different).

class Solution {
public:
    // Checks if the Hamming distance between two strings is exactly 1
    bool hamming(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        int diff = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                if (++diff > 1) return false;
            }
        }
        return diff == 1;
    }

    // Returns the longest valid subsequence as per the problem constraints
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);     // dp[i]: length of longest valid subsequence starting at i
        vector<int> nxt(n, -1);   // nxt[i]: index of next word in the optimal path
        int max_len = 0, start = -1;

        // Bottom-up DP to fill dp[] and track the path via nxt[]
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (groups[i] != groups[j] && hamming(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        nxt[i] = j;
                    }
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                start = i;
            }
        }

        // Reconstruct the sequence
        vector<string> result;
        while (start != -1) {
            result.push_back(words[start]);
            start = nxt[start];
        }
        return result;
    }
};
