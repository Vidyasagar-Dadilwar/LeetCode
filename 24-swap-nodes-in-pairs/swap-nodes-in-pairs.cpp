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
    ListNode* solve(ListNode* t1, ListNode* t2){
        if(t1==NULL && t2==NULL){
            return NULL;
        }
        if(t2==NULL){
            return t1;
        }
        t1->next=t2->next;
        t2->next=t1;

        t1->next=solve(t1->next, t1->next?t1->next->next:NULL);
        return t2;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* t1=head, *t2=head->next;
        return solve(t1, t2);
    }
};