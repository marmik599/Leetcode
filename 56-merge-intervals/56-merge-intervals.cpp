class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size()==1)
            return intervals;
        vector<vector<int>> mergedintervals;  
        
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++)
        {
            vector<int> maxi;
            int maxi1=INT_MIN;
           int mini1=intervals[i][0];
            while(i<intervals.size()-1 && (intervals[i][1]>=intervals[i+1][0] ||maxi1>=intervals[i+1][0]))
            {
                maxi1=max(maxi1,intervals[i][1]);
                maxi1=max(maxi1,intervals[i+1][1]);
                //mini1=intervals[i][0];
                
                
                i++;
            }
            if(maxi1==INT_MIN )
            {
                mini1=intervals[i][0];
                maxi1=intervals[i][1];
            }
            maxi.push_back(mini1);
            maxi.push_back(maxi1);
            
            mergedintervals.push_back(maxi);
            
        }
        return mergedintervals;
    }
};