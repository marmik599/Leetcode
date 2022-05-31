class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
      vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
    void solve(vector<int> nums,int i,vector<vector<int>>& ans)
    {
        if(i == nums.size()-1)
            ans.push_back(nums);
        else
        {
            for(int j=i;j<nums.size();j++)
            {
                if(i!=j && nums[i]==nums[j])
                    continue;
                swap(nums[i],nums[j]);
                solve(nums,i+1,ans);
            }
        }
    }
};