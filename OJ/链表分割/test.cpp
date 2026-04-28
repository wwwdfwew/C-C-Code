
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* phead, int x) {
        if (phead == NULL)
            return NULL;
        struct ListNode* pHead = phead;
        struct ListNode* newlist1 = NULL;
        struct ListNode* newlist2 = NULL;
        struct ListNode* tail1 = NULL;
        struct ListNode* tail2 = NULL;
        while (pHead)
        {
            if (pHead->val < x)
            {
                if (newlist1 == NULL)
                {
                    newlist1 = tail1 = pHead;
                }
                else
                {
                    tail1->next = pHead;
                    tail1 = pHead;
                }
                pHead = pHead->next;
            }
            else
            {
                if (newlist2 == NULL)
                {
                    newlist2 = tail2 = pHead;
                }
                else
                {
                    tail2->next = pHead;
                    tail2 = pHead;
                }
                pHead = pHead->next;
            }
        }
        if (tail1 && tail2)
        {
            tail1->next = newlist2;
            tail2->next = NULL;
            phead = newlist1;
        }
        else if (tail1)
        {
            phead = newlist1;
        }
        else
        {
            phead = newlist2;
        }
        return phead;
    }
};