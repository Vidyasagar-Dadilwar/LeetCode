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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1, *h2 = l2;
        ListNode *ans = new ListNode(-1);
        ListNode *arr = ans;
        int sum = 0, carry = 0;
        while(h1 != NULL && h2 != NULL){
            sum += h1->val + h2->val + carry;
            ListNode *tmp = new ListNode(sum%10);
            carry = sum / 10;
            arr->next = tmp;
            arr = arr->next;
            sum = 0;
            h1 = h1->next, h2 = h2->next;
        }
        while(h1 != NULL){
            sum += h1->val + carry;
            ListNode *tmp = new ListNode(sum%10);
            carry = sum / 10;
            arr->next = tmp;
            arr = arr->next;
            sum = 0;
            h1 = h1->next;
        }
        while(h2 != NULL){
            sum += h2->val + carry;
            ListNode *tmp = new ListNode(sum%10);
            carry = sum / 10;
            arr->next = tmp;
            arr = arr->next;
            sum = 0;
            h2 = h2->next;
        }
        if(carry){
            ListNode* tmp = new ListNode(carry);
            arr->next = tmp;
            arr = arr->next;
        }
        return ans->next;
    }
};