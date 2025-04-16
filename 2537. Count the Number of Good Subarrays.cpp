// Problem: 2537. Count the Number of Good Subarrays
// Difficulty: Hard
// Topic: Sliding Window, Hash Map
// Link: https://leetcode.com/problems/count-the-number-of-good-subarrays
// Approach:
//   - Maintain a sliding window where the number of good pairs is at least k
//   - Use a hash map to count frequencies and calculate pair contribution
//   - Shrink the window from the left until current pair count < k
//   - If current pair count >= k, all subarrays ending here and starting from 0 to i are valid
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        long long ans = 0;
        long long cur = 0;
        int i = 0;
        for (int& x : nums) {
            cur += cnt[x]++;
            while (cur - cnt[nums[i]] + 1 >= k) {
                cur -= --cnt[nums[i++]];
            }
            if (cur >= k) {
                ans += i + 1;
            }
        }
        return ans;
    }
};
