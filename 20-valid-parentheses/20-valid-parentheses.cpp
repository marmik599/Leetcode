class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(c=='(' || c=='[' || c=='{')
                st.push(c);
            
            else
            {
                if(!st.empty())
                {
                    char temp=st.top();
                    if(temp=='(' && c==')' || temp=='[' && c==']' || temp=='{' && c=='}')
                    {
                        st.pop();
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        
        return false;
    }
};