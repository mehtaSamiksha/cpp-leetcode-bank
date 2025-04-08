// Problem: 2874. Maximum Value of an Ordered Triplet II
// Difficulty: Medium
// Topic: Arrays, Greedy
// Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii
// Approach: Greedy with tracking max(nums[i]) and max(nums[i] - nums[j])
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long ans = 0;
        int maxDiff = 0;  // max(nums[i] - nums[j])
        int maxNum = 0;   // max(nums[i])

        for (const int num : nums) {
            ans = max(ans, static_cast<long>(maxDiff) * num);  // num := nums[k]
            maxDiff = max(maxDiff, maxNum - num);              // num := nums[j]
            maxNum = max(maxNum, num);                         // num := nums[i]
        }

        return ans;
    }
};
