// Problem: 2302. Count Subarrays With Score Less Than K
// Difficulty: Medium
// Topics: Array, Binary Search, Prefix Sum
// Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
// Approach:
//   - Use prefix sum to calculate subarray sums efficiently.
//   - For each subarray ending at index i, use binary search to find the maximum valid length.
//   - Add the number of valid subarrays to the answer.
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long prefixSum[n + 1];
        prefixSum[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        long long answer = 0;
        for (int i = 1; i <= n; ++i) {
            int left = 0, right = i;
            while (left < right) {
                int mid = (left + right + 1) >> 1;
                if ((prefixSum[i] - prefixSum[i - mid]) * mid < k) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            answer += left;
        }
        return answer;
    }
};
