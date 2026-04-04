struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    struct ListNode* prve = head;
    struct ListNode* cur = head->next;
    while (cur)
    {
        if (cur->val == prve->val)
        {
            prve->next = cur->next;
            cur = prve->next;
        }
        else
        {
            prve = cur;
            cur = cur->next;
        }
    }
    return head;
}