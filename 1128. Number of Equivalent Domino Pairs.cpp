// Problem: 1128. Number of Equivalent Domino Pairs
// Difficulty: Easy
// Topics: Array, Hash Table
// Link: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Approach:
//   - Treat each domino as a number by sorting its two elements (e.g., (a, b) becomes min(a, b) * 10 + max(a, b)).
//   - Use a hash table to count occurrences of each domino configuration.
//   - The number of equivalent domino pairs can be determined by counting pairs of occurrences.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt[100]{};  // To store frequency of each domino configuration
        int ans = 0;
        for (auto& e : dominoes) {
            int x = e[0] < e[1] ? e[0] * 10 + e[1] : e[1] * 10 + e[0];  // Normalize domino order
            ans += cnt[x]++;  // Count equivalent pairs
        }
        return ans;
    }
};
