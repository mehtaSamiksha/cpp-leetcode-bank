// Problem: 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
// Difficulty: Medium
// Link: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
// Topics: Greedy, Math
// Approach:
//   - Replace all zeros with 1 (minimum allowed).
//   - Compute sum1 and sum2 after replacement.
//   - If sums are equal, return either.
//   - If not equal, check if the smaller sum can be increased (i.e., that array had at least one 0).
//   - If so, return max(sum1, sum2), else return -1.

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        bool hasZero = false;

        for (int x : nums1) {
            hasZero |= x == 0;
            s1 += max(x, 1);
        }

        for (int x : nums2) {
            s2 += max(x, 1);
        }

        if (s1 > s2) return minSum(nums2, nums1); // always keep s1 <= s2
        if (s1 == s2) return s1;
        return hasZero ? s2 : -1;
    }
};
