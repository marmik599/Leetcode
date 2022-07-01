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
    bool validate(TreeNode* root,long max,long min)
    {
       if(root==NULL)
           return true;
        
        if(root->val > min && root->val < max)
        {
            bool left=validate(root->left,root->val,min);
            bool right=validate(root->right,max,root->val);
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) 
    {
      return validate(root,LONG_MAX,LONG_MIN);  
    }
};