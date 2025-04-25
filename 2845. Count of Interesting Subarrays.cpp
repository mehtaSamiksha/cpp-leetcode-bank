// Problem: 2845. Count of Interesting Subarrays
// Difficulty: Medium
// Topics: Prefix Sum, Hash Map, Modulo Arithmetic
// Link: https://leetcode.com/problems/count-of-interesting-subarrays/
// Approach:
//   - Convert nums to a binary array where arr[i] = 1 if nums[i] % modulo == k.
//   - Use prefix sum and a hash map to count how many previous prefix sums satisfy the condition.
// Time Complexity: O(n)
// Space Complexity: O(modulo) ~ O(n) in worst case

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = int(nums[i] % modulo == k);
        }

        unordered_map<int, int> cnt;
        cnt[0] = 1;
        long long ans = 0;
        int s = 0;

        for (int x : arr) {
            s += x;
            ans += cnt[(s - k + modulo) % modulo];
            cnt[s % modulo]++;
        }

        return ans;
    }
};
