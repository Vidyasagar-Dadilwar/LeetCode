#include <unordered_set>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (head != nullptr) {
            if (numSet.find(head->val) == numSet.end()) {
                tail->next = new ListNode(head->val);
                tail = tail->next;
            }
            head = head->next;
        }
        
        return dummy.next;
    }
};