// Problem: 3337. Total Characters in String After Transformations II
// Difficulty: Hard
// Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/
// Topics: Matrix Exponentiation, String, Counting, Simulation
// Time Complexity: O(26^3 * log(t))
// Space Complexity: O(26^2)
// Explanation:
// - Model the character transitions using a 26x26 matrix.
// - Raise the matrix to the power `t` using fast exponentiation.
// - Multiply the final matrix by the initial frequency vector of characters.
// - Sum the transformed frequencies to get the final result modulo 1e9+7.

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    static constexpr int M = 26;
    using Matrix = vector<vector<int>>;

    // Multiply two matrices under modulo
    Matrix matmul(const Matrix& a, const Matrix& b) {
        int n = a.size(), p = b.size(), q = b[0].size();
        Matrix res(n, vector<int>(q, 0));
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < p; ++k)
                if (a[i][k])
                    for (int j = 0; j < q; ++j)
                        res[i][j] = (res[i][j] + 1LL * a[i][k] * b[k][j] % MOD) % MOD;
        return res;
    }

    // Fast matrix exponentiation
    Matrix matpow(Matrix mat, int power) {
        Matrix res(M, vector<int>(M, 0));
        for (int i = 0; i < M; ++i) res[i][i] = 1;  // Identity matrix
        while (power) {
            if (power & 1) res = matmul(res, mat);
            mat = matmul(mat, mat);
            power >>= 1;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> cnt(M, 0);
        for (char c : s)
            ++cnt[c - 'a'];

        // Build transformation matrix
        Matrix matrix(M, vector<int>(M, 0));
        for (int i = 0; i < M; ++i)
            for (int j = 1; j <= nums[i]; ++j)
                matrix[i][(i + j) % M] = 1;

        // Frequency vector as a 1x26 matrix
        Matrix cntMat(1, vector<int>(M));
        for (int i = 0; i < M; ++i)
            cntMat[0][i] = cnt[i];

        Matrix factor = matpow(matrix, t);
        Matrix result = matmul(cntMat, factor);

        int ans = 0;
        for (int x : result[0])
            ans = (ans + x) % MOD;

        return ans;
    }
};
