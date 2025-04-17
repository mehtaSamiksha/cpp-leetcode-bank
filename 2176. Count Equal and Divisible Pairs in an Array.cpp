// Problem: 2176. Count Equal and Divisible Pairs in an Array
// Difficulty: Easy
// Topic: Array, Brute Force
// Link: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array
// Approach:
//   - Use two nested loops to iterate over all pairs (i, j) such that i < j
//   - Check if nums[i] == nums[j] and (i * j) % k == 0
//   - If both conditions are satisfied, increment the count
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        for (int j = 1; j < nums.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                ans += nums[i] == nums[j] && (i * j % k) == 0;
            }
        }
        return ans;
    }
};
