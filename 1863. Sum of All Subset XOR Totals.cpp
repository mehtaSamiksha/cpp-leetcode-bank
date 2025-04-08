// Problem: 1863. Sum of All Subset XOR Totals
// Difficulty: Easy
// Topic: Bit Manipulation, Backtracking, Math
// Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals
// Approach: All subset XOR total is (XOR of all elements) * 2^(n-1)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_or<>())
               << (nums.size() - 1);
    }
};
