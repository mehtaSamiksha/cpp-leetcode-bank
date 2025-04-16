// Problem: 141. Linked List Cycle
// Difficulty: Easy
// Topic: Linked List, Two Pointers
// Link: https://leetcode.com/problems/linked-list-cycle
// Approach:
//   - Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare)
//   - Move one pointer (slow) by 1 step and the other (fast) by 2 steps
//   - If there’s a cycle, they will eventually meet
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};
