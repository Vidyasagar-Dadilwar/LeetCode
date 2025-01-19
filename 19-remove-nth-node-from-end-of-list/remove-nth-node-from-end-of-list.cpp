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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }
        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        n = size - n;
        temp = head;
        while(n > 1){
            temp = temp->next;
            n--;
        }
        ListNode* temp2 = temp->next;
        temp->next = temp->next->next;
        delete(temp2);
        return head;
    }
};