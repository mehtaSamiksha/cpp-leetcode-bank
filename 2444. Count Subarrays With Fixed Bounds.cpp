// Problem: 2444. Count Subarrays With Fixed Bounds
// Difficulty: Hard
// Topics: Sliding Window, Greedy
// Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
// Approach:
//   - Track the latest occurrence of minK and maxK using j1 and j2.
//   - Track the last invalid index (where nums[i] is out of [minK, maxK]) using k.
//   - For each i, valid subarrays end at i if both minK and maxK are included.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int j1 = -1, j2 = -1, k = -1;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                k = i;
            }
            if (nums[i] == minK) {
                j1 = i;
            }
            if (nums[i] == maxK) {
                j2 = i;
            }
            ans += max(0, min(j1, j2) - k);
        }
        return ans;
    }
};
