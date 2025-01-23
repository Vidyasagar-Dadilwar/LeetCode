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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        while(left < right){
            ListNode* l = head;
            ListNode* r = head;
            for(int i=1; i<left; i++){
                l = l->next;
            }
            for(int i=1; i<right; i++){
                r = r->next;
            }
            swap(l->val, r->val);
            left++;
            right--;
        }
        return head;
    }
};