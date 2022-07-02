class Solution {
public:bool ispal(string s)
    {
        int start=0;
        int end=s.length()-1;
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>> &res,vector<string> &temp,string s)
    {
        if(s=="")
        {
            res.push_back(temp);
            return;
        }
        
        for(int j=0;j<s.size();j++)
        {
            string left=s.substr(0,j+1);
            string right=s.substr(j+1);
            if(ispal(left))
            {
                temp.push_back(left);
                solve(res,temp,right);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> temp;
        int n=s.length();
        solve(res,temp,s);
        return res;
    }
    
    
};