/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbersHelper(ListNode *node1, ListNode *node2, int carry)
    {
        if (node1 == NULL && node2 == NULL && carry == 0)
        {
            // Added both the lists and no carry is generated.
            return NULL;
        }

        // 'val1' and 'val2' store the data of the current nodes of the two linked lists.
        int val1, val2;

        // 'next1' and 'next2' point to the node present after the current nodes of the two linked lists.
        ListNode *next1, *next2;

        if (node1 == NULL)
        {
            // List 1 is empty. So, consider the current node's value as zero.
            val1 = 0;
            // And the node after the current node as NULL.
            next1 = NULL;
        }
        else
        {
            val1 = node1->val;
            next1 = node1->next;
        }

        if (node2 == NULL)
        {
            // List 2 is empty. So, consider the current node's value as zero.
            val2 = 0;
            // And the node after the current node as NULL.
            next2 = NULL;
        }
        else
        {
            val2 = node2->val;
            next2 = node2->next;
        }

        // Add the values in the current nodes along with the carry.
        int sum = val1 + val2 + carry;

        // Create the next node of the sum list.
        ListNode *sumNode = new ListNode(sum % 10);

        // Recursively call the function to generate the remaining nodes of the sum list.
        sumNode->next = addTwoNumbersHelper(next1, next2, sum / 10);

        return sumNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersHelper(l1,l2,0);
    }
};