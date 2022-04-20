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
    vector<double> averageOfLevels(TreeNode* root) 
    {
          queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<double>> ans;
        vector<double> in;
        vector<double> out;
        
        
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            
            q.pop();
            
            if(temp==NULL)
            {
                ans.push_back(in);
                
                if(!q.empty())
                {
                    q.push(NULL);
                    in.clear();
                }
            }
            else
            {
                in.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                    
            if(temp->right)
                q.push(temp->right); 
            }    
    }
    
         for(int i=0;i<ans.size();i++)
         {      double sum=0;
             for(int j=0;j<ans[i].size();j++)
             {
                 sum=sum+ans[i][j];
                 
             }
                sum=sum/ans[i].size();
                out.push_back(sum);
         }
        return out;
        
    
    }
};