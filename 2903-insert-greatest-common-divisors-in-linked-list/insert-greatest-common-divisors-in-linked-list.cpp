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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* t1 = head;
        if(head->next == NULL){
            return head;
        }
        ListNode* t2 = t1->next;
        while(t2 != NULL){
            ListNode* temp = new ListNode(__gcd(t1->val, t2->val));
            t1->next = temp;
            temp->next = t2;
            t1 = t1->next->next;
            t2 = t2->next;
        }
        return head;
    }
};