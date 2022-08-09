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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
        
    }
    TreeNode* build(vector<int>&in, int inS, int inE, vector<int>&post, int postS, int postE, map<int,int>&mp)
    {
        if((postS>postE)||(inS>inE))
            return NULL;
        
        TreeNode* root = new TreeNode(post[postE]);
        
        int inRoot = mp[post[postE]];
        int numL = inRoot - inS;
        
        root->left = build(in, inS, inRoot-1, post, postS, postS+numL-1, mp);
        
        root->right = build(in, inRoot+1, inE, post, postS+numL, postE-1,mp);
        
        return root;
    }
};