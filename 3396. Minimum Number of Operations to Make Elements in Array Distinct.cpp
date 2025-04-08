// Problem: 3396. Minimum Number of Operations to Make Elements in Array Distinct
// Difficulty: Medium
// Topic: Hashing, Greedy
// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct
// Approach: Traverse from end, track seen elements using a set, return ceil(i / 3) on duplicate
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = nums.size() - 1; ~i; --i) {
            if (s.contains(nums[i])) {
                return i / 3 + 1;
            }
            s.insert(nums[i]);
        }
        return 0;
    }
};
