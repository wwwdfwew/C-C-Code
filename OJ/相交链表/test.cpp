size_t size(ListNode* list)
{
    ListNode* mylist = list;
    size_t size = 1;
    while (mylist->next != nullptr)
    {
        size++;
        mylist = mylist->next;
    }
    return size;
}
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* myheadA = headA;
        ListNode* myheadB = headB;
        if (myheadA == nullptr || myheadB == nullptr)
            return nullptr;
        size_t min = size(myheadA);
        size_t max = size(myheadB);
        if (min > max)
        {
            myheadA = headB;
            myheadB = headA;
            size_t tmp = min;
            min = max;
            max = tmp;
        }
        size_t n = max - min;
        while (n--)
        {
            myheadB = myheadB->next;
        }

        for (size_t i = 0; i < min; i++)
        {
            if (myheadA == myheadB)
                return myheadA;
            else
            {
                if (myheadA->next && myheadB->next)
                {
                    myheadA = myheadA->next;
                    myheadB = myheadB->next;
                }
            }
        }
        return nullptr;
    }
};