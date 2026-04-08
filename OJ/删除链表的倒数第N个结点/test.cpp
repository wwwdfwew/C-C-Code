struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* frist = head;
    struct ListNode* slow = head;
    struct ListNode* cur = head;
    while (n--)
        frist = frist->next;
    while (frist)
    {
        cur = slow;
        frist = frist->next;
        slow = slow->next;
    }
    if (slow == head)
        return slow->next;
    else
    {
        cur->next = slow->next;
        free(slow);
        return head;
    }
}