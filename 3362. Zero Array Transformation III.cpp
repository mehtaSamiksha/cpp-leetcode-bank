// Problem: 3362. Zero Array Transformation III
// Link: (Add problem link if available)
// Tags: Greedy, Priority Queue, Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Description:
//   - Given nums array and queries as intervals [l, r], 
//     apply minimal queries to reduce nums[i] to 0 for all i.
//   - Return the maximum number of queries that can remain unused,
//     or -1 if not possible.

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> used_query; // Min-heap: queries currently applied (by end)
        priority_queue<int> available_query; // Max-heap: queries available to apply (by end)
        sort(queries.begin(), queries.end()); // Sort queries by start point

        int query_pos = 0;
        int applied_count = 0;
        for (int i = 0; i < n; ++i) {
            // Add all queries starting at index i to available_query
            while (query_pos < (int)queries.size() && queries[query_pos][0] == i) {
                available_query.push(queries[query_pos][1]);
                query_pos++;
            }

            // Account for queries already applied overlapping at i
            nums[i] -= (int)used_query.size();

            // Apply queries if nums[i] still > 0
            while (nums[i] > 0 && !available_query.empty() && available_query.top() >= i) {
                used_query.push(available_query.top());
                available_query.pop();
                nums[i]--;
                applied_count++;
            }

            // If unable to reduce nums[i] to zero, return -1
            if (nums[i] > 0) return -1;

            // Remove all used queries that end at i
            while (!used_query.empty() && used_query.top() == i) {
                used_query.pop();
            }
        }

        return (int)queries.size() - applied_count;
    }
};
