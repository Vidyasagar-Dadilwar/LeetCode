class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr) {
            if (st.count(curr->val)) 
                prev->next = curr->next;
            else 
                prev = curr;
            curr = curr->next;
        }
        return dummy.next;
    }
};