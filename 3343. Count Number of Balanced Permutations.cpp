// Problem: 3343. Count Number of Balanced Permutations
// Difficulty: Hard
// Topics: Combinatorics, Dynamic Programming, Bitmask
// Link: https://leetcode.com/problems/count-number-of-balanced-permutations/
// Approach:
//   - Count digit frequency.
//   - Use DP with memoization to try assigning each digit to left and right halves such that both have equal sum.
//   - Precompute binomial coefficients for permutations.
//   - State: f[i][sum][left][right] where
//     i = current digit, sum = target half sum, left/right = number of remaining slots.
// Time Complexity: O(10 * s/2 * (n/2)^2)
// Space Complexity: O(10 * s/2 * (n/2)^2)

using ll = long long;
const int MX = 80;
const int MOD = 1e9 + 7;
ll c[MX][MX];

auto init = [] {
    c[0][0] = 1;
    for (int i = 1; i < MX; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    return 0;
}();

class Solution {
public:
    int countBalancedPermutations(string num) {
        int cnt[10]{};
        int s = 0;
        for (char& ch : num) {
            ++cnt[ch - '0'];
            s += ch - '0';
        }
        if (s % 2 != 0) return 0;

        int n = num.size();
        int half = s / 2;
        int f[10][half + 1][n / 2 + 1][n / 2 + 2];
        memset(f, -1, sizeof(f));

        auto dfs = [&](auto&& self, int i, int j, int a, int b) -> int {
            if (i > 9) return ((j | a | b) == 0 ? 1 : 0);
            if (a == 0 && j) return 0;
            if (f[i][j][a][b] != -1) return f[i][j][a][b];

            int ans = 0;
            for (int l = 0; l <= min(cnt[i], a); ++l) {
                int r = cnt[i] - l;
                if (r >= 0 && r <= b && l * i <= j) {
                    int ways = c[a][l] * c[b][r] % MOD;
                    int recur = self(self, i + 1, j - l * i, a - l, b - r);
                    ans = (ans + ways * 1LL * recur % MOD) % MOD;
                }
            }
            return f[i][j][a][b] = ans;
        };

        return dfs(dfs, s / 2, s / 2, n / 2, (n + 1) / 2);
    }
};
