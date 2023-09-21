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
    ListNode* helper(ListNode *l1, ListNode *l2,int carry)
    {
        if(l1==NULL && l2==NULL && carry==0)
            return NULL;
        int val1, val2;
        ListNode *next1, *next2;
        if(l1==NULL)
        {
            val1 = 0;
            next1 = NULL;
        }
        else
        {
            val1 = l1->val;
            next1 = l1->next;
        }
        if(l2==NULL)
        {
            val2 = 0;
            next2 = NULL;
        }
        else
        {
            val2 = l2->val;
            next2 = l2->next;
        }

        int sum = val1+val2+carry;
        ListNode* sumNode = new ListNode(sum%10);

        sumNode->next = helper(next1,next2,sum/10);
        return sumNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1,l2,0);
    }
};