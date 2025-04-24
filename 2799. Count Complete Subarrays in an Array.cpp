// Problem: 2799. Count Complete Subarrays in an Array
// Difficulty: Medium
// Topic: Sliding Window, HashSet
// Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array
// Approach: Brute-force with nested loop and set to count distinct elements in subarrays
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> fullSet(nums.begin(), nums.end()); // Get all distinct elements
        int totalDistinct = fullSet.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            for (int j = i; j < n; ++j) {
                seen.insert(nums[j]);
                if (seen.size() == totalDistinct)
                    ++ans;
            }
        }

        return ans;
    }
};
