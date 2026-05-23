/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* newnode = NULL;
    struct ListNode* dst = head;
    struct ListNode* cur = head->next;
    while (dst)
    {
        dst->next = newnode;
        newnode = dst;
        dst = cur;
        if (cur)
            cur = cur->next;
    }
    return newnode;
}