struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* prve = head;
    struct ListNode* end = head;
    int count = 0;
    int sum = 0;
    while (cur)
    {
        if (cur->val == 0)
            count++;
        cur = cur->next;
    }

    while (count--)
    {
        while (prve->val != 0)
            prve = prve->next;
        while (end && (end->val != 0 || end == prve))
            end = end->next;
        cur = prve->next;
        while (cur != end && cur)
        {
            sum += cur->val;
            cur = cur->next;
        }
        if (end)
        {
            prve->val = sum;
            prve->next = end;
            prve = end;
        }
        sum = 0;

    }
    struct ListNode* cur1 = head;
    while (cur1->next != prve)
        cur1 = cur1->next;
    cur1->next = prve->next;
    return head;
}
