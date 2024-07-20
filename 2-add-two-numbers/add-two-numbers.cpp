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
    ListNode* createLinkedList(const vector<int>& values) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* current = dummy_head;

        for (int val : values) {
            current->next = new ListNode(val);
            current = current->next;
        }
        return dummy_head->next;
    }

    void solve(ListNode* l1, ListNode* l2, vector<int>&res, int carry){
        if (!l1 && !l2 && carry == 0) {
            return;
        }
        int sum = (l1?l1->val:0)+(l2?l2->val:0)+carry;
        carry=sum/10;
        res.push_back(sum%10);
        solve(l1?l1->next:nullptr, l2?l2->next:nullptr, res, carry);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> res;
        int carry = 0;
        solve(l1, l2, res, carry);
        return createLinkedList(res);
    }
};