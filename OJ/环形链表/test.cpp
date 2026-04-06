struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA, * tailB = headB;
    int lengA = 1;
    int lengB = 1;
    while (tailA->next) { tailA = tailA->next; lengA++; }
    while (tailB->next) { tailB = tailB->next; lengB++; }
    if (tailA != tailB)return NULL;
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    if (lengA < lengB)
    {
        longlist = headB;
        shortlist = headA;
    }
    int g = abs(lengA - lengB);
    while (g--)
    {
        longlist = longlist->next;
    }
    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* frist = head;
    struct ListNode* slow = head;
    while (frist && frist->next)
    {
        frist = frist->next->next;
        slow = slow->next;
        if (frist == slow)
        {
            frist = frist->next;
            slow->next = NULL;
            return getIntersectionNode(frist, head);
        }
    }
    return NULL;
}