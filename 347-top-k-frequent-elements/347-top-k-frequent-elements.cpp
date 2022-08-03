class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> q;
        for(auto i:mp)
        {
            q.push({i.second,i.first});
        }
        vector<int> ans;
        while(k>0 && !q.empty())
        {
            auto i=q.top();
            q.pop();
            ans.push_back(i.second);
            k--;
        }
        return ans;
    }
};