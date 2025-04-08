// Problem: 2140. Solving Questions With Brainpower
// Difficulty: Medium
// Topic: Dynamic Programming
// Link: https://leetcode.com/problems/solving-questions-with-brainpower
// Approach: Bottom-up DP (Iterative)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            int nextIndex = i + brainpower + 1;

            long long solve = points + (nextIndex < n ? dp[nextIndex] : 0);
            long long skip = dp[i + 1];

            dp[i] = max(solve, skip);
        }

        return dp[0];
    }
};
