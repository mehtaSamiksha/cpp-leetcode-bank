// Problem: 1922. Count Good Numbers
// Difficulty: Medium
// Topic: Math, Modular Exponentiation
// Link: https://leetcode.com/problems/count-good-numbers
// Approach:
//   - Even positions (0-based) can be 0, 2, 4, 6, 8 → 5 choices
//   - Odd positions can be prime digits (2, 3, 5, 7) → 4 choices
//   - Use fast exponentiation to compute (5^even) * (4^odd) % mod
// Time Complexity: O(log n) for fast exponentiation
// Space Complexity: O(1)

class Solution {
public:
    int countGoodNumbers(long long n) {
        const int mod = 1e9 + 7;
        auto qpow = [](long long x, long long n) -> long long {
            long long res = 1;
            while (n) {
                if ((n & 1) == 1) {
                    res = res * x % mod;
                }
                x = x * x % mod;
                n >>= 1;
            }
            return res;
        };
        return qpow(5, (n + 1) >> 1) * qpow(4, n >> 1) % mod;
    }
};
