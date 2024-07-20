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
    ListNode* generateList(vector<int> arr){
        ListNode* dummyNode=new ListNode(0);
        ListNode* curr = dummyNode;
        for(int i=0; i<arr.size(); i++){
            curr->next=new ListNode(arr[i]);
            curr=curr->next;
        }
        return dummyNode->next;
    }
    ListNode* solve(ListNode* l1, ListNode* l2, vector<int>& res){
        if(l1==NULL && l2==NULL){
            return generateList(res);
        }
        if(l1 == NULL) {
            res.push_back(l2->val);
            return solve(l1, l2->next, res);
        }

        if(l2 == NULL) {
            res.push_back(l1->val);
            return solve(l1->next, l2, res);
        }
        if(l1->val < l2->val){
            res.push_back(l1->val);
            return solve((l1)?l1->next:nullptr, l2, res);
        }
        else{
            res.push_back(l2->val);
            return solve(l1, (l2)?l2->next:nullptr, res);
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int>res;
        return solve(l1, l2, res);
    }
};