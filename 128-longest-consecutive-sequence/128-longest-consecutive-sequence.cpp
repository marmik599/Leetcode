class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            
                if(mp.find(nums[i]-1)!=mp.end())
                {
                    mp[nums[i]]=0;
                }
            
                
        }
        int mlength=0;
        for(int i=0;i<n;i++)
        {
            int length=0;
            if(mp[nums[i]]==1)
            {
                length++;
                while(mp.find(nums[i]+length)!=mp.end())
                {
                    length++;
                }
                mlength=max(mlength,length);
            }
            
        }
        return mlength;
        
    }
};