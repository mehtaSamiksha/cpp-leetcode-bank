// Problem: 73. Set Matrix Zeroes
// Link: https://leetcode.com/problems/set-matrix-zeroes/
// Tags: Array, Matrix, Simulation
// Time Complexity: O(m * n)
// Space Complexity: O(1) – constant extra space (in-place using first row/column)
// Description:
//   - Given an m x n integer matrix, if an element is 0, set its entire row and column to 0.
//   - Do it in-place with constant extra space.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool shouldFillFirstRow = false;
        bool shouldFillFirstCol = false;

        // Check if the first row needs to be zeroed
        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0) {
                shouldFillFirstRow = true;
                break;
            }

        // Check if the first column needs to be zeroed
        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0) {
                shouldFillFirstCol = true;
                break;
            }

        // Use first row and column to mark zero locations
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        // Set matrix cells to zero based on markers
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // Zero out the first row if needed
        if (shouldFillFirstRow)
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;

        // Zero out the first column if needed
        if (shouldFillFirstCol)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};
