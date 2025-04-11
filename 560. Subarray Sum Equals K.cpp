// Problem: 560. Subarray Sum Equals K
// Difficulty: Medium
// Topic: Prefix Sum, Hash Table
// Link: https://leetcode.com/problems/subarray-sum-equals-k
// Approach: Use a prefix sum and a hash map to count how many times a specific
//           prefix sum has occurred. For each current sum, check how many times
//           (current prefix sum - k) has appeared so far.
// Time Complexity: O(n), where n is the size of the array
// Space Complexity: O(n), for the hash map storing prefix sums

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> count{{0, 1}};  // {prefix sum: count}

    for (const int num : nums) {
      prefix += num;
      const int target = prefix - k;
      if (const auto it = count.find(target); it != count.cend())
        ans += it->second;
      ++count[prefix];
    }

    return ans;
  }
};
