// Problem: 368. Largest Divisible Subset
// Difficulty: Medium
// Topic: Dynamic Programming, Sorting
// Link: https://leetcode.com/problems/largest-divisible-subset
// Approach: Sort the array, use DP to track the length of divisible chains
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int f[n];
        int k = 0;

        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            if (f[k] < f[i]) {
                k = i;
            }
        }

        int m = f[k];
        vector<int> ans;
        for (int i = k; m > 0; --i) {
            if (nums[k] % nums[i] ==
