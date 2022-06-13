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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        bool flag=true;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int siz=q.size();
            vector<int> level(siz);
            for(int i=0;i<siz;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                int index=flag?i:siz-1-i;
                level[index]=temp->val;
                
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
            flag=!flag;
            ans.push_back(level);
        }
        return ans;
        
    }
};