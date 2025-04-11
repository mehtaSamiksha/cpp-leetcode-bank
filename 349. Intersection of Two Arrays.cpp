// Problem: 349. Intersection of Two Arrays
// Difficulty: Easy
// Topic: Hash Table, Set
// Link: https://leetcode.com/problems/intersection-of-two-arrays
// Approach: Use an unordered_set to store elements from nums1. Iterate through nums2,
//           and for each match (and successful erase to ensure uniqueness), add to result.
// Time Complexity: O(n + m), where n and m are sizes of nums1 and nums2
// Space Complexity: O(n), for the hash set storing nums1 elements

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_set<int> set{nums1.begin(), nums1.end()};

    for (const int num : nums2)
      if (set.erase(num))  // returns 1 if num existed and was removed
        ans.push_back(num);

    return ans;
  }
};
