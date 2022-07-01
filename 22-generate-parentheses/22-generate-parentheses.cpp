class Solution {
public:
    void solve(vector<string> &ans,string temp,int total,int i,int counto,int countc)
    {
        if(i==total)
        {
            ans.push_back(temp);
            return;
        }
        if(counto>countc)
        {
            if(counto<total/2)
                solve(ans,temp+'(',total,i+1,counto+1,countc);
            solve(ans,temp+')',total,i+1,counto,countc+1);
            return;
        }
        else if(counto==countc)
        {
            solve(ans,temp+'(',total,i+1,counto+1,countc);
            return;
        }
        return;
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        if(n==1)
        {
            ans.push_back("()");
            return ans;
        }
        solve(ans,"",2*n,0,0,0);
        return ans;
    }
};