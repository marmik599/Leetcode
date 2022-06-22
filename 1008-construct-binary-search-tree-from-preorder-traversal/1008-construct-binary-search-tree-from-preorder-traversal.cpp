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
    TreeNode* solve(vector<int> preorder,int mini,int maxi,int &index)
    {
        if(index>=preorder.size() )
        {
            return NULL;
        }
        if(preorder[index]<mini || preorder[index]>maxi)
            return NULL;
        
        
            int lim=preorder[index++];
            TreeNode* root=new TreeNode(lim);
            root->left=solve(preorder,mini,lim,index);
            root->right=solve(preorder,lim,maxi,index);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int maxi=INT_MAX;
        int mini=INT_MIN;
        int index=0;
        return solve(preorder,mini,maxi,index);
    }
};