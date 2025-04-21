// Problem: 2563. Count the Number of Fair Pairs
// Difficulty: Medium
// Topic: Binary Search, Two Pointers, Sorting
// Link: https://leetcode.com/problems/count-the-number-of-fair-pairs
// Approach: Sort the array and use lower_bound to count valid pairs (i, j) such that lower <= nums[i] + nums[j] <= upper
// Time Complexity: O(n log n)
// Space Complexity: O(1) (excluding sort space)

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            auto j = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto k = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1);
            ans += k - j;
        }
        return ans;
    }
};
