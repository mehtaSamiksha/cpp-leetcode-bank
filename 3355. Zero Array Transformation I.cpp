// Problem: 3355. Zero Array Transformation I
// Link: https://leetcode.com/problems/zero-array-transformation-i/
// Tags: Greedy, Prefix Sum, Difference Array
// Time Complexity: O(n)
// Space Complexity: O(n)
// Description:
//   - You're given an integer array `nums` and a list of queries, where each query
//     is a range [l, r] representing a decrement of 1 for all elements in the range.
//   - Determine whether you can perform all queries in any order such that no element
//     in `nums` becomes negative.

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int diff[n + 1];  // Difference array to track range update counts
        memset(diff, 0, sizeof(diff));

        // Apply all range updates using difference array technique
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            ++diff[l];
            --diff[r + 1];
        }

        // Convert difference array to actual usage by prefix summing
        for (int i = 0, total = 0; i < n; ++i) {
            total += diff[i];
            if (nums[i] > total) {
                return false;  // Not enough operations to reduce nums[i] to zero
            }
        }

        return true;
    }
};
