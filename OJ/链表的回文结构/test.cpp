struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* frist = head;
    struct ListNode* slow = head;
    while (frist && frist->next)
    {
        frist = frist->next->next;
        slow = slow->next;
    }
    return slow;
}
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* prve = head;
    struct ListNode* tail = prve->next;
    while (tail)
    {
        struct ListNode* Next = tail->next;
        tail->next = prve;
        prve = tail;
        tail = Next;
    }
    head->next = NULL;
    return prve;

}
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        ListNode* B = A;
        struct ListNode* pos = reverseList(middleNode(B));
        while (pos)
        {
            if (pos->val != A->val)
                return false;
            pos = pos->next;
            A = A->next;
        }
        return true;
    }
};