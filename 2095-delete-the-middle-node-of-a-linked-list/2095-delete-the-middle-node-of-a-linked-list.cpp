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
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == nullptr) 
            return nullptr;

        ListNode* prv = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr) {
            prv = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* nxt = slow -> next;
        prv -> next = nxt;
        slow -> next = nullptr;
        delete(slow);
        return head;
    }
};