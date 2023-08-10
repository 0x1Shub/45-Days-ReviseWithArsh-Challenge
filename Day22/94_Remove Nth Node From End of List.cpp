class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *cur = head;
        int len = 0;

        while (cur)
        {
            ++len;
            cur = cur->next;
        }

        if (n == len)
        {
            // delete the head
            ListNode *ans = head->next;
            delete head;
            return ans;
        }

        cur = head;
        for (int i = 0; i < len; ++i)
        {
            if (i == len - n - 1)
            {
                // the node previous to the node to be deleted
                ListNode *to_delete = cur->next;
                cur->next = cur->next->next;
                delete to_delete;
                break;
            }
            cur = cur->next;
        }

        return head;
    }
};