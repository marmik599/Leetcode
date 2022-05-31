class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums)
    {
     vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
    void solve(vector<int> nums,int i,vector<vector<int>>& ans) 
    {
       if(i==nums.size())
           ans.push_back(nums);
        
        else
        {
            for(int j=i;j<nums.size();j++)
            {
                swap(nums[i],nums[j]);
                solve(nums,i+1,ans);
            }
        }
    }
};