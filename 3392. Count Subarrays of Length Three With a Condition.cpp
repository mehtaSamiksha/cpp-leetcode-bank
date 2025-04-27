// Problem: 3392. Count Subarrays of Length Three With a Condition
// Difficulty: Easy
// Topics: Array, Math
// Link: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/
// Approach:
//   - For each middle element nums[i], check if nums[i] is the average of nums[i-1] and nums[i+1].
//   - If yes, increment the answer.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i + 1 < nums.size(); ++i) {
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
