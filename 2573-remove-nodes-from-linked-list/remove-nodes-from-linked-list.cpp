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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nextTemp = nullptr;
        while (cur != nullptr) {
            nextTemp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTemp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        int maxi = 0;
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            maxi = max(maxi, cur->val);

            if (cur->val < maxi) {
                prev->next = cur->next;
                ListNode* deleted = cur;
                cur = cur->next;
                deleted->next = nullptr;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return reverse(head);
    }
};