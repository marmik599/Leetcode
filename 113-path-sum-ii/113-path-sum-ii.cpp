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
   
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> v;
        vector<vector<int>> ans;
        
        solve(root,targetSum,v,ans);
        return ans;
        
    }
    void solve(TreeNode* root,int targetSum,vector<int> v,vector<vector<int>> &answer)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(targetSum==root->val)
            {
                v.push_back(root->val);
               answer.push_back(v);
            }
            
        }
        v.push_back(root->val);
        solve(root->left,targetSum-root->val,v,answer);
        solve(root->right,targetSum-root->val,v,answer);
    }
};