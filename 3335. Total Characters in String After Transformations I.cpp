// Problem: 3335. Total Characters in String After Transformations I
// Difficulty: Medium
// Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/
// Topics: String, Simulation, Counting
// Approach:
//   - Count occurrences of each character in the string.
//   - Simulate `t` transformations where:
//     - 'a' -> 'b', ..., 'y' -> 'z'
//     - 'z' -> "ab" which affects counts of both 'a' and 'b'
//   - Return total number of characters modulo 1e9 + 7.
// Time Complexity: O(t)
// Space Complexity: O(1)

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        constexpr int kMod = 1'000'000'007;
        vector<int> count(26);

        for (const char c : s)
            ++count[c - 'a'];

        while (t-- > 0) {
            vector<int> newCount(26);
            for (int i = 0; i < 25; ++i)
                newCount[i + 1] = count[i];
            newCount[0] = count[25];
            newCount[1] = (newCount[1] + count[25]) % kMod;
            count = std::move(newCount);
        }

        return accumulate(count.begin(), count.end(), 0L) % kMod;
    }
};
