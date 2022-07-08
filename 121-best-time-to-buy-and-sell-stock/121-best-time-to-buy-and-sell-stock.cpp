class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size()==1)
            return 0;
        int maxdiff=prices[1]-prices[0];
        int minval=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            maxdiff=max(maxdiff,prices[i]-minval);
            minval=min(minval,prices[i]);
        }
        if(maxdiff<=0)
            return 0;
        return maxdiff;
    }
};