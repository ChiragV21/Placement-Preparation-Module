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
struct info
{
    bool isbst;
    int min;
    int max;
    int sum;
    int ans;
};
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        
        struct info res=fun(root);
        return res.ans;
    }
    struct info fun(TreeNode* root)
    {
        if(root==NULL)
        {
            return {true,INT_MAX,INT_MIN,0,0};
        }
        
        struct info result;
        
        struct info left=fun(root->left);
        struct info right=fun(root->right);
        
        if((left.isbst==true and right.isbst==true) and (root->val>left.max and root->val<right.min))
        {
           result.isbst=true;    
        }
        else
        {
            result.isbst=false;
        }
        
        result.min=min(root->val,min(left.min,right.min));
        result.max=max(root->val,max(left.max,right.max));
        
        result.sum=left.sum+right.sum+root->val;
        
        if(result.isbst==true)
        {
           result.ans=max(result.sum,max(left.ans,right.ans));
        }
        else if(result.isbst==false)
        {
            result.ans=max(left.ans,right.ans);
        }
        return result;
    }
};