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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> v;
        int sum=0;
        solve(root,sum,targetSum,v,ans);
        return ans;
        
    }
    void solve(TreeNode* root,int sum,int targetSum,vector<int> v,vector<vector<int>> &answer)
    {
        if(root==NULL)
            return;
        
        sum+=root->val;
         v.push_back(root->val);
         
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
            {
               ans.push_back(v);
            }
               
            
            return;
        }
        solve(root->left,sum,targetSum,v,ans);
        solve(root->right,sum,targetSum,v,ans);
    }
};