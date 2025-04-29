// Problem: 2962. Count Subarrays Where Max Element Appears at Least K Times
// Difficulty: Medium
// Topics: Array, Sliding Window
// Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
// Approach:
//   - Identify the maximum value in the array.
//   - Use a sliding window where we maintain a count of how many times the max element appears.
//   - For each valid window (where max element appears ≥ k times), add all subarrays ending at the current right pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        int cnt = 0, j = 0;
        for (int x : nums) {
            while (j < n && cnt < k) {
                cnt += nums[j++] == mx;
            }
            if (cnt < k) {
                break;
            }
            ans += n - j + 1;
            cnt -= x == mx;
        }
        return ans;
    }
};
