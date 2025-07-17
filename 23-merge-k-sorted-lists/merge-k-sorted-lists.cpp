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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto list: lists){
            while(list != NULL){
                pq.push(list->val);
                list = list->next;
            }
        }
        ListNode* l = new ListNode(-1);
        ListNode* ans = l;
        while(!pq.empty()){
            l->next = new ListNode(pq.top());
            pq.pop();
            l = l->next;
        }
        return ans->next;
    }
};