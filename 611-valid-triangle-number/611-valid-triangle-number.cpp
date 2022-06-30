class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(),nums.end()); 
        int ans=0;
        for(int right=nums.size()-1;right>=2;right--)
        {
            int left=0;
            int mid=right-1;
            while(left<mid)
            {
                if(nums[left]+nums[mid]>nums[right])
                {
                    ans+=mid-left;
                    mid--;
                }
                else
                    left++;
            }
        }
        return ans;
    }
};