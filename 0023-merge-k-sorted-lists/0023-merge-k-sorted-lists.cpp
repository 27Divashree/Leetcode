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
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;

        int k = listArray.size();
        if(k==0)
            return NULL;
        //step1:
        for(int i=0;i<k;i++){
            if(listArray[i]!=NULL)
                minHeap.push(listArray[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(minHeap.size()>0){
            ListNode* temp = minHeap.top();
            minHeap.pop();

            if(temp->next!=NULL)
                    minHeap.push(temp->next);

            if(head==NULL)
            {
                //answer LL is empty
                head = temp;
                tail = temp;
            }
            else
            {
                //insert at LL
                tail->next = temp;
                tail = temp;
            }
        }
        return head;

    }
};