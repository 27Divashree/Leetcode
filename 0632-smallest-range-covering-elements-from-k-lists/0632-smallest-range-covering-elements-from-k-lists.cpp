class Solution {
    
public:
    struct node{
        int data;int row;int col;
        node(int d,int r, int c):
        data(d), row(r), col(c) {}
    };

    struct compare{
        bool operator()(node a,node b){
            return a.data > b.data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX, maxi = INT_MIN, range= INT_MAX;
        int k = nums.size();

        priority_queue<node, vector<node>, compare> minHeap;

        //step 1: create a minHeap for starting element of each list and tracking min/max value
        for(int i=0;i<k;++i){
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            node t(nums[i][0], i, 0);
            minHeap.push(t);
        }

        int start = mini, end = maxi;

        while(!minHeap.empty())
        {
            //mini fetch
            node temp = minHeap.top();
            minHeap.pop();

            mini = temp.data;

            //range or answer updation
            if(maxi-mini < range){
                start = mini;
                end = maxi;
                range = maxi-mini;
            }

            // if we don't have anymore elements in the row of min element, we're done
            if(temp.col + 1 == nums[temp.row].size())
                break;
            // if we still have atleast one element push it inside the min heap
            node next(nums[temp.row][temp.col + 1], temp.row, temp.col + 1);
            minHeap.push(next);
            // update the currMax if the next element is bigger than this
            if(next.data > maxi)
                maxi = next.data;
        }

        return {start,end};

    }
};