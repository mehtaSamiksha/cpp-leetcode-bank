// Problem: 790. Domino and Tromino Tiling
// Difficulty: Medium
// Topics: Dynamic Programming
// Link: https://leetcode.com/problems/domino-and-tromino-tiling/
// Approach:
//   - Use DP with 4 states representing partial tilings:
//     f[0]: full tiling up to i,
//     f[1], f[2]: one-square gaps (top or bottom),
//     f[3]: corner-shaped gaps.
//   - Transition based on domino and tromino placements.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;
        long long f[4] = {1, 0, 0, 0};
        for (int i = 1; i <= n; ++i) {
            long long g[4];
            g[0] = (f[0] + f[1] + f[2] + f[3]) % mod;
            g[1] = (f[2] + f[3]) % mod;
            g[2] = (f[1] + f[3]) % mod;
            g[3] = f[0];
            memcpy(f, g, sizeof(g));
        }
        return f[0];
    }
};
