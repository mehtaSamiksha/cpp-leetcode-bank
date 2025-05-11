// Problem: 1550. Three Consecutive Odds
// Difficulty: Easy
// Link: https://leetcode.com/problems/three-consecutive-odds/
// Topics: Array
// Approach:
//   - Iterate through the array while counting consecutive odd numbers.
//   - Reset the count if an even number is encountered.
//   - If count reaches 3, return true.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (int x : arr) {
            if (x & 1) {
                if (++cnt == 3) return true;
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};
