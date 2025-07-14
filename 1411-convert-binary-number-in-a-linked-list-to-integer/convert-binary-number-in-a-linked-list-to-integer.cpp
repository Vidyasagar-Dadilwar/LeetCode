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
    void solve(ListNode* head, string& s){
        if(!head)
            return ;
        s += (head->val + '0');
        solve(head->next, s);
    }
    int getDecimalValue(ListNode* head) {
        string s = "";
        solve(head, s);
        return std::stoi(s, nullptr, 2);
    }
};