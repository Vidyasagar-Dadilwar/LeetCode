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
    int traverse(ListNode *head) {
        int len = 0;
        while(head) {
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1,*temp2;
        // temp1 will contain lower length list and temp2 will contain bigger length list
        if(traverse(l1) <= traverse(l2)) {
            temp1 = l1;
            temp2 = l2;
        }
        else {
            temp1 = l2;
            temp2 = l1;
        }
        ListNode *head = NULL;
        ListNode *curr;
        int carry = 0;
        while(temp1) {
            int val = temp1 -> val + temp2 -> val + carry;
            if(val >= 10) {
                carry = 1;
                val = val % 10;
            }
            else
                carry = 0;
            ListNode *t = new ListNode(val);
            if(head == NULL) {
                head = t;
                curr = head;
            }
            else {
                curr -> next = t;
                curr = curr -> next;
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        while(temp2) {
            int val = temp2 -> val + carry;
            if(val >= 10) {
                val = val % 10;
                carry = 1;
            }
            else
                carry = 0;
            ListNode *t = new ListNode(val);
            curr -> next = t;
            curr = curr -> next;
            temp2 = temp2 -> next;
        }
        if(carry) {
            ListNode *t = new ListNode(carry);
            curr -> next = t;
            curr = curr -> next;
        }
        return head;
    }
};