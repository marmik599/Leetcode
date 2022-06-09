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
    bool ans=false;
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
       int sum=0;
        if(root==NULL)
            return false;
       solve(root,sum,targetSum);
        return ans;
    }
    void solve(TreeNode* root,int sum,int targetSum)
    {
        if(root==NULL)
            return;
        
        sum+=root->val;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
                ans=true;
            
            return;
        }
        solve(root->left,sum,targetSum);
        solve(root->right,sum,targetSum);
    }
};