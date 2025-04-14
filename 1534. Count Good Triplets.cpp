// Problem: 1534. Count Good Triplets
// Difficulty: Easy
// Topic: Brute Force, Array
// Link: https://leetcode.com/problems/count-good-triplets
// Approach:
//   - Iterate through all triplets (i, j, k) with i < j < k
//   - Count the triplet if it satisfies the three absolute difference conditions
// Time Complexity: O(n^3)
// Space Complexity: O(1)

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    ans += abs(arr[i] - arr[j]) <= a &&
                           abs(arr[j] - arr[k]) <= b &&
                           abs(arr[i] - arr[k]) <= c;
                }
            }
        }
        return ans;
    }
};
