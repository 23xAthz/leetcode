/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    // temporary list
    struct ListNode dummy;
    dummy.next = NULL;

    // this is apointer that points to the last node of the list
    struct ListNode* tail = &dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // we create a new node for the current digit

        struct ListNode* node =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        node->val = sum % 10;
        node->next = NULL;

        carry = sum / 10;

        tail->next = node;
        tail = node;
    }

    return dummy.next;
}
