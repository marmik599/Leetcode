class Solution {
public:
   
       int maxProfit(vector<int>& P) {
        int profit = 0;
        for(int i = 1; i < size(P); i++) {
            if(P[i] > P[i-1]) {
                profit += P[i] - P[i-1];
            }
        }
        return profit;
    }
   
};