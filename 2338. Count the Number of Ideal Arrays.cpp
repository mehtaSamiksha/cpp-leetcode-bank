// Problem: 2338. Count the Number of Ideal Arrays
// Difficulty: Hard
// Topic: Math, DP, Combinatorics
// Link: https://leetcode.com/problems/count-the-number-of-ideal-arrays
// Approach: Use DP with memoization and precomputed combinations.
//           Each valid array is built by extending numbers through their multiples,
//           and for each path, combinatorics determine how many such arrays exist.
// Time Complexity: O(maxValue * log(maxValue) * n)
// Space Complexity: O(maxValue * n)

class Solution {
public:
    int m, n;
    const int mod = 1e9 + 7;
    vector<vector<int>> f; // DP memoization: f[i][cnt] stores result for value i with cnt elements
    vector<vector<int>> c; // Precomputed combinations

    int idealArrays(int n, int maxValue) {
        this->m = maxValue;
        this->n = n;
        f.assign(maxValue + 1, vector<int>(16, -1));
        c.assign(n, vector<int>(16, 0));

        // Precompute combinations (nCr)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= i && j < 16; ++j)
                c[i][j] = !j ? 1 : (c[i - 1][j] + c[i - 1][j - 1]) % mod;

        int ans = 0;
        for (int i = 1; i <= m; ++i)
            ans = (ans + dfs(i, 1)) % mod;
        return ans;
    }

    // DFS to explore sequences starting from i with length cnt
    int dfs(int i, int cnt) {
        if (f[i][cnt] != -1) return f[i][cnt];

        int res = c[n - 1][cnt - 1]; // Choose (cnt-1) positions to extend
        if (cnt < n)
            for (int k = 2; k * i <= m; ++k)
                res = (res + dfs(k * i, cnt + 1)) % mod;

        return f[i][cnt] = res;
    }
};
