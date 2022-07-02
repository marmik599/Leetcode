class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &temp,int i,int target,vector<int> v)
    {
        if(i==v.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        
        if(target>=v[i])
        {
            temp.push_back(v[i]);
            solve(ans,temp,i,target-v[i],v);
            temp.pop_back();
        }
        solve(ans,temp,i+1,target,v);
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,0,target,candidates);
        return ans;
    }
};