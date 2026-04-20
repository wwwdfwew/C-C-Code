#include <stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode* m_pNext;
}ListNode;

ListNode* Creaknode(ListNode** pphead, int x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->m_pNext = NULL;
    newnode->val = x;
    if (*pphead == NULL)
        *pphead = newnode;
    else
    {
        ListNode* cur = *pphead;
        while (cur->m_pNext)
        {
            cur = cur->m_pNext;
        }
        cur->m_pNext = newnode;
    }
    return *pphead;
}

int main() {
    int n = 0;
    int arr[1000];
    int k = 0;
    ListNode* head = NULL;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            head = Creaknode(&head, arr[i]);
        }
        scanf("%d", &k);
        ListNode* frist = head;
        ListNode* slow = head;

        while (k--)
            frist = frist->m_pNext;
        while (frist && frist->m_pNext)
        {
            frist = frist->m_pNext;
            slow = slow->m_pNext;
        }
        if (head->m_pNext == NULL)
            printf("%d\n", slow->val);
        else
            printf("%d\n", slow->m_pNext->val);
    }
    return 0;
}