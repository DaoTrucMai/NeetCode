/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

/*Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]*/

#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNums(struct ListNode *L1, struct ListNode *L2)
{
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;

    struct ListNode *tail = &dummy;
    int remember = 0;

    while (L1 != NULL || L2 != NULL || remember != 0)
    {
        int sum = remember;

        if (L1 != NULL)
        {
            sum += L1->val;
            L1 = L1->next;
        }

        if (L2 != NULL)
        {
            sum += L2->val;
            L2 = L2->next;
        }

        remember = sum / 10;
        int digit = sum % 10;

        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = digit;
        node->next = NULL;

        tail->next = node;
        tail = node;
    }
    return dummy.next;
}