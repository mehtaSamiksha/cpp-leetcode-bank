// Problem: 3375. Minimum Operations to Make Array Values Equal to K
// Difficulty: Medium
// Topic: HashSet, Greedy
// Link: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k
// Approach:
//   - All elements must be ≥ k; if any element < k, return -1
//   - Track the minimum value in the array and unique elements
//   - Return total unique elements minus one if minimum is exactly k (no op needed for that value)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        int mi = INT_MAX;
        for (int x : nums) {
            if (x < k) {
                return -1;
            }
            mi = min(mi, x);
            s.insert(x);
        }
        return s.size() - (mi == k);
    }
};
