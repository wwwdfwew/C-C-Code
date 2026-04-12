struct ListNode* Greatnewnode()
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = 0;
    newnode->next = NULL;
    return newnode;
}
struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    struct ListNode* head = Greatnewnode();
    struct ListNode* cur3 = head;
    int add = 0;
    while (cur1 && cur2)
    {
        if ((cur1->val + cur2->val + add) < 10)
        {
            struct ListNode* newnode = Greatnewnode();
            newnode->val = cur1->val + cur2->val + add;
            add = 0;
            cur3->next = newnode;
            cur3 = cur3->next;
        }
        else
        {
            struct ListNode* newnode = Greatnewnode();
            newnode->val = (cur1->val + cur2->val + add) % 10;
            add = 1;
            cur3->next = newnode;
            cur3 = cur3->next;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    while (cur1)
    {
        if ((cur1->val + add) < 10)
        {
            struct ListNode* newnode = Greatnewnode();
            newnode->val = cur1->val + add;
            add = 0;
            cur3->next = newnode;
            cur3 = cur3->next;
        }
        else
        {
            struct ListNode* newnode = Greatnewnode();
            newnode->val = (cur1->val + add) % 10;
            add = 1;
            cur3->next = newnode;
            cur3 = cur3->next;
        }
        cur1 = cur1->next;
    }
    while (cur2)
    {
        if ((cur2->val + add) < 10)
        {
            struct ListNode* newnode = Greatnewnode();
            newnode->val = cur2->val + add;
            add = 0;
            cur3->next = newnode;
            cur3 = cur3->next;
        }
        else
        {
            struct ListNode* newnode = Greatnewnode();
            newnode->val = (cur2->val + add) % 10;
            add = 1;
            cur3->next = newnode;
            cur3 = cur3->next;
        }
        cur2 = cur2->next;
    }
    if (add)
    {
        struct ListNode* newnode = Greatnewnode();
        newnode->val = add;
        cur3->next = newnode;
        cur3 = cur3->next;
    }
    return head->next;
}

struct ListNode* rollback(struct ListNode* ps)
{
    struct ListNode* prve = ps;
    struct ListNode* cur = ps->next;
    prve->next = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = prve;
        prve = cur;
        cur = next;
    }
    return prve;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1 = rollback(l1);
    l2 = rollback(l2);
    return rollback(addTwoNumbers1(l1, l2));
}