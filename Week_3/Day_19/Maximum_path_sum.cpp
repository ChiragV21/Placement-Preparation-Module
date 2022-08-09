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
    int height(TreeNode* root, int& sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int l = max(0,height(root->left, sum));
        int r = max(0,height(root->right, sum));
        
        sum = max(sum, l+r+root->val);
        
        return (root->val)+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        height(root, sum);
        return sum;
        
    }
};