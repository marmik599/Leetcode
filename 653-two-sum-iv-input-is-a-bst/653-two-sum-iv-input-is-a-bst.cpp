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
    void inorder(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
            return ;
        
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool isSum(TreeNode* root,int target)
    {
        vector<int> ans;
        inorder(root,ans);
        int l=0;
        int h=ans.size()-1;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        while(l<h)
        {
            if(ans[l]+ans[h]==target)
                return true;
            else if(ans[l]+ans[h]>target)
                h--;
            else
                l++;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) 
    {
        return isSum(root,k);
    }
};