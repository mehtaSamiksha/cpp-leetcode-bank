// Problem: 350. Intersection of Two Arrays II
// Difficulty: Easy
// Topic: Hash Table, Sorting
// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii
// Approach: Use a hash map to count elements in the smaller array. 
//           Then iterate through the second array, decreasing the count
//           in the map and adding common elements to the result.
// Time Complexity: O(n + m), where n and m are the sizes of nums1 and nums2
// Space Complexity: O(min(n, m)), for the hash map

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
      return intersect(nums2, nums1);

    vector<int> ans;
    unordered_map<int, int> count;

    for (const int num : nums1)
      ++count[num];

    for (const int num : nums2)
      if (const auto it = count.find(num);
          it != count.cend() && it->second-- > 0)
        ans.push_back(num);

    return ans;
  }
};
