//  You are given two non - empty linked lists representing two non - negative integers.
//  The digits are stored in reverse order, and each of their nodes contains a single digit.
//  Add the two numbersand return the sum as a linkedt.

//  You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//  Example
//  [2]->[4]->[3]
//  [5]->[6]->[4]
//  -------------
//  [7]->[0]->[8]


//  Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
//  Output : [7, 0, 8]
//  Explanation : 342 + 465 = 807.


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
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }
};