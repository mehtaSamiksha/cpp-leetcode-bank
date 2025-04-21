// Problem: 2145. Count the Hidden Sequences
// Difficulty: Medium
// Topic: Prefix Sum, Math
// Link: https://leetcode.com/problems/count-the-hidden-sequences
// Approach: Track prefix sum to find min and max values reached. The valid range must fit within [lower, upper].
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long x = 0, mi = 0, mx = 0;
        for (int d : differences) {
            x += d;
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return max(upper - lower - (mx - mi) + 1, 0LL);
    }
};
