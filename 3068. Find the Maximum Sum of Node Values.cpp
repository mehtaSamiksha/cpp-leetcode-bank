// Problem: 3068. Find the Maximum Sum of Node Values
// Link: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/
// Tags: Dynamic Programming, Bit Manipulation, Graph
// Time Complexity: O(n)
// Space Complexity: O(1)
// Description:
//   - Given an array `nums` representing node values,
//     and a constant `k`, you can optionally XOR the value of each node with `k`.
//   - Select a subset of edges such that no two selected edges share a node,
//     and the sum of the values of the connected nodes (after optional XOR) is maximized.

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long f0 = 0;                       // max sum using even number of XORs
        long long f1 = -0x3f3f3f3f;             // max sum using odd number of XORs

        for (int x : nums) {
            long long tmp = f0;
            f0 = max(f0 + x, f1 + (x ^ k));     // no XOR or using a previous XOR'd node
            f1 = max(f1 + x, tmp + (x ^ k));    // add x or XOR x if previous was un-XORed
        }

        return f0;  // Only even XORs are valid since edges are matched in pairs
    }
};
