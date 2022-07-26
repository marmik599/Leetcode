class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int start=0;start<=n-3;start++)
        {
            int j=start+1;
            int end=n-1;
            while(j<end)
            {
                int sum=nums[start]+nums[end]+nums[j];
                if(sum==target)
                {
                    return sum;
                }
                if(abs(sum-target)<abs(ans-target))
                {
                    ans=sum;
                }
                if(sum<target)
                {
                    j++;
                }
                else
                {
                    end--;
                }
                 
                
            }
        }
        return ans;
        
        
    }
};