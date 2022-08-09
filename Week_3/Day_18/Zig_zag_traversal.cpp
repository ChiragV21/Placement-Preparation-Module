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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*>q;
        bool flag=true;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            vector<int>res(s);
            for(int i=0;i<s;i++)
            {
                TreeNode* n = q.front();
                q.pop();
                int ind = (flag) ? i : s-1-i;
                res[ind] = n->val;
                if(n->left)
                {
                    q.push(n->left);
                }
                if(n->right)
                {
                    q.push(n->right);
                }
                
            }
            flag=!flag;
            ans.push_back(res);
        }
        return ans;
    }
};