/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        long long sum =0, count = 0;
        while(q.size())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(!curr)
            {
                ans.push_back((double) sum/count);
                sum = 0, count = 0;
                q.push(NULL);
                if(!q.front())
                    break;
            }
            else
            {
                count++;
                sum+=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }

        return ans;
    }
};