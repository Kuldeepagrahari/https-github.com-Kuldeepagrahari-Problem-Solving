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
    void solve(ListNode* &prev, ListNode* &cur) {
        if(cur == nullptr) return;
        ListNode* nxt = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = nxt;
        solve(prev, cur);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        solve(prev, head);
        return prev;
    }
};