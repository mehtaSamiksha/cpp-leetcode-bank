// Problem: 153. Find Minimum in Rotated Sorted Array
// Difficulty: Medium
// Topic: Binary Search
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
// Approach: Binary Search by comparing mid and right
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            const int m = (l + r) / 2;
            if (nums[m] < nums[r])
                r = m;
            else
                l = m + 1;
        }

        return nums[l];
    }
};
