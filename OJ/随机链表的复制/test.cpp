struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    struct Node* node[1000];
    int count = 0;
    while (cur)
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        node[count++] = newnode;
        newnode->val = cur->val;
        newnode->next = cur->next;
        cur->next = newnode;
        cur = newnode->next;
    }
    struct Node* cur1 = head;
    while (cur1)
    {
        if (cur1->random == NULL)
            cur1->next->random = NULL;
        else
        {
            cur1->next->random = cur1->random->next;
        }
        cur1 = cur1->next->next;
    }
    for (int i = 0; i < count - 1; i++)
        node[i]->next = node[i + 1];
    return node[0];
}