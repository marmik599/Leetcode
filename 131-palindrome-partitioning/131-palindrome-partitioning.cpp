class Solution {
public:bool ispal(string s,int start,int end)
    {
        
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>> &res,vector<string> &temp,int i,string s,int n)
    {
        if(i==n)
        {
            res.push_back(temp);
            return;
        }
        
        for(int j=i;j<n;j++)
        {
            if(ispal(s,i,j))
            {
                temp.push_back(s.substr(i,j-i+1));
                solve(res,temp,j+1,s,n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> temp;
        int n=s.length();
        solve(res,temp,0,s,n);
        return res;
    }
    
    
};