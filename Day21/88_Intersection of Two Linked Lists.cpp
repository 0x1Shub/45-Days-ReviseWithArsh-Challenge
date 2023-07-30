/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> node_set;
        ListNode *curr = headA;
        while (curr)
        {
            node_set.insert(curr);
            curr = curr->next;
        }

        // go through nodes in list B, if the current node is in the set, return it
        curr = headB;
        while (curr)
        {
            if (node_set.find(curr) != node_set.end())
            {
                return curr;
            }
            curr = curr->next;
        }

        return nullptr;
    }
};