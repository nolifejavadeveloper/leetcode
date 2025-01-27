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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* returnValue = new ListNode();
        ListNode* current;
        current = returnValue;

        while (l1 || l2 || carry > 0) {
            int v1 = 0, v2 = 0;
            if (l1 != nullptr) {
                v1 = l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                v2 = l2->val;
                l2 = l2->next;
            }
          
            int added = v1 + v2 + carry;
            carry = 0;
            if (added > 9) {
                added -=10;
                carry = 1;
            }
            
            ListNode* newNode = new ListNode(added);
            current->next = newNode;
            current = newNode;
        }

        return returnValue->next;
    }
};
