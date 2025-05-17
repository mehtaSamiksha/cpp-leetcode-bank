// Problem: 75. Sort Colors
// Link: https://leetcode.com/problems/sort-colors/
// Tags: Array, Two Pointers, Sorting, Dutch National Flag
// Time Complexity: O(n)
// Space Complexity: O(1)
// Description:
//   - Given an array with values 0 (red), 1 (white), and 2 (blue),
//     sort them in-place so that the same colors are adjacent in the order 0 → 1 → 2.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1; // Last index where 0 is placed
        int one  = -1; // Last index where 1 is placed
        int two  = -1; // Last index filled overall

        for (const int num : nums) {
            if (num == 0) {
                nums[++two] = 2;
                nums[++one] = 1;
                nums[++zero] = 0;
            } else if (num == 1) {
                nums[++two] = 2;
                nums[++one] = 1;
            } else {
                nums[++two] = 2;
            }
        }
    }
};
