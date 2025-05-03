// Problem: 1007. Minimum Domino Rotations For Equal Row
// Difficulty: Medium
// Topics: Array, Greedy
// Link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// Approach:
//   - Try to make all values in the top or bottom row equal to tops[0] or bottoms[0].
//   - For each candidate value x, check how many rotations are needed.
//   - Return the minimum number of rotations or -1 if it's not possible.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        auto check = [&](int x) {
            int countTop = 0, countBottom = 0;
            for (int i = 0; i < n; ++i) {
                if (tops[i] != x && bottoms[i] != x) {
                    return n + 1;
                }
                countTop += tops[i] == x;
                countBottom += bottoms[i] == x;
            }
            return n - max(countTop, countBottom);
        };
        int result = min(check(tops[0]), check(bottoms[0]));
        return result > n ? -1 : result;
    }
};
