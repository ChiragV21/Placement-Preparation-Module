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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (!root)
            return {};

        vector<vector<int>> ourRes; 
        vector<int> singleIter;     
                                    
        queue<TreeNode *> ourNodes;

        ourNodes.push(root);

        while (!ourNodes.empty())
        {
            int size = ourNodes.size();
            while (size--)
            {
                TreeNode *topElement = ourNodes.front();
                singleIter.push_back(topElement->val);
                ourNodes.pop();
                if (topElement->left)
                    ourNodes.push(topElement->left);
                if (topElement->right)
                    ourNodes.push(topElement->right);
            }
            ourRes.push_back(singleIter);
            singleIter.clear();
        }

        return ourRes;
    }
};