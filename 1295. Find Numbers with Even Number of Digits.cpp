// Problem: 1295. Find Numbers with Even Number of Digits
// Difficulty: Easy
// Topics: Array
// Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Approach:
//   - A number has an even number of digits if it's in the ranges:
//     10–99, 1000–9999, or exactly 100000.
//   - Count how many numbers in the array fall in these ranges.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int num : nums)
            if (9 < num && num < 100 || 999 < num && num < 10000 || num == 100000)
                ++ans;
        return ans;
    }
};
