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
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            ++len;
        }
        p = head;
        int ans = 0;
        while (p) {
            --len;
            if (p->val) {
                ans |= (1 << len);
            }
            p = p->next;
        }
        return ans;
    }
};
