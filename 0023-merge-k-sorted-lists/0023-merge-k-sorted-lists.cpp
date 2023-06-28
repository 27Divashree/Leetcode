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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& listArray) {        
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int n = listArray.size();
        if(n==0)
            return 0;

        for(int i=0;i<n;i++){
            if(listArray[i]!=NULL)
                minHeap.push(listArray[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(minHeap.size()>0)
        {
            ListNode* temp = minHeap.top();
            minHeap.pop();

            if(temp->next!=NULL)
                minHeap.push(temp->next);
            
            if(head==NULL)
            {
                head = temp;
                tail = temp;
            }

            else
            {
                tail->next = temp;
                tail = temp;
            }
        }

        return head;
    }
};