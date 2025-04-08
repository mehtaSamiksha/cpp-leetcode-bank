// Problem: 416. Partition Equal Subset Sum
// Difficulty: Medium
// Topic: Dynamic Programming, Subset Sum
// Link: https://leetcode.com/problems/partition-equal-subset-sum
// Approach: 2D DP where f[i][j] = true if sum j can be formed using first i elements
// Time Complexity: O(n * sum/2)
// Space Complexity: O(n * sum/2)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2 == 1) return false;

        int n = nums.size();
        int m = s / 2;
        bool f[n + 1][m + 1];
        memset(f, false, sizeof(f));
        f[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            for (int j = 0; j <= m; ++j) {
                f[i][j] = f[i - 1][j] || (j >= x && f[i - 1][j - x]);
            }
        }

        return f[n][m];
    }
};
