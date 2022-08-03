class Solution {
public:
    int solve(int index,string s,vector<int> &dp)
    {
       
        
        if(index==s.size())
            return 1;
         if(s[index]=='0')
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        
        int first=solve(index+1,s,dp);
        int second=0;
        if( index< s.size()-1 && (s[index]=='1' || (s[index]=='2' && s[index+1]<='6')))
            second=solve(index+2,s,dp);
            
        return dp[index]=first+second;
    }
    int numDecodings(string s)
    {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return solve(0,s,dp);
    }
};