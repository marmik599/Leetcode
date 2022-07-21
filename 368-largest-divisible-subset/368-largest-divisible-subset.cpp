class Solution {
public:
   
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n,-1);
        int maxi=0;
  
        for(int i=1;i<n;i++)
        {
           
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1)
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>dp[maxi])
            {
                maxi=i;
                //lastindex=i;
            }
            
        }
        vector<int> ans;
            for(;maxi>=0;maxi=hash[maxi])
                ans.push_back(nums[maxi]);
            //reverse(ans.begin(),ans.end());
        return ans;
    }
};