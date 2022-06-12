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
    int totalcount(TreeNode* root)
    {
    if(root==NULL)
    return 0;
    
    return 1+totalcount(root->left)+totalcount(root->right);
    }
    bool iscbt(TreeNode* root,int i,int nodecount)
    {
        if(root==NULL)
            return true;
        
        if(i>=nodecount)
            return false;
        else
            return iscbt(root->left,2*i+1,nodecount) && iscbt(root->right,2*i+2,nodecount);
    }
    bool isCompleteTree(TreeNode* root) 
    {
        int i=0;
        int nodecount=totalcount(root);
        cout<<nodecount<<" ";
        return iscbt(root,i,nodecount);
    }
    
};