// Problem: 2094. Finding 3-Digit Even Numbers
// Difficulty: Easy
// Link: https://leetcode.com/problems/finding-3-digit-even-numbers/
// Topics: Array, Hash Table
// Approach:
//   - Count the frequency of each digit.
//   - For each 3-digit even number from 100 to 998, check if it can be formed using the digits.
//   - If valid, add it to the answer list.
// Time Complexity: O(900 * 10) = O(1)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10]{};
        for (int x : digits) {
            ++cnt[x];
        }
        vector<int> ans;
        for (int x = 100; x < 1000; x += 2) {
            int cnt1[10]{};
            for (int y = x; y; y /= 10) {
                ++cnt1[y % 10];
            }
            bool ok = true;
            for (int i = 0; i < 10 && ok; ++i) {
                ok = cnt[i] >= cnt1[i];
            }
            if (ok) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
