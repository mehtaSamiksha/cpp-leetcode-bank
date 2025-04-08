// Problem: 34. Find First and Last Position of Element in Sorted Array
// Difficulty: Medium
// Topic: Binary Search
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
// Approach: Modified Binary Search (Run twice: for leftmost and rightmost positions)
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution { 
public:     
    vector<int> searchRange(vector<int>& nums, int target) {         
        vector<int> ans(2, -1);         
        int n = nums.size();         
        int low = 0;         
        int high = n - 1;         
        
        // First occurrence
        while (low <= high) {             
            int mid = low + (high - low) / 2;             
            if (nums[mid] < target)                 
                low = mid + 1;             
            else if (nums[mid] > target)                 
                high = mid - 1;             
            else {                 
                ans[0] = mid;                 
                high = mid - 1;        
            }         
        }         
        
        low = 0;         
        high = n - 1;         

        // Last occurrence
        while (low <= high) {             
            int mid = low + (high - low) / 2;             
            if (nums[mid] < target)                 
                low = mid + 1;             
            else if (nums[mid] > target)                 
                high = mid - 1;             
            else {                 
                ans[1] = mid;                 
                low = mid + 1;            
            }         
        }         
        return ans;     
    } 
};
