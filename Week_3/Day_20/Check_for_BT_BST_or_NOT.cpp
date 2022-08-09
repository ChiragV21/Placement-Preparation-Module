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
    bool check(TreeNode* root, long long int l, long long int r)
    {
        if(root == NULL)
            return true;
        int v = root->val;
        if(v<=l || v>= r)
            return false;
        return (check(root->left, l, v) && check(root->right, v, r));
    }
    bool isValidBST(TreeNode* root) {
        long long int inf = pow(2,31)+1;
        return check(root, -inf, inf);
        
    }
};