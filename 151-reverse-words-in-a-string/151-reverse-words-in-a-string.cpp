class Solution {
public:
   
    string reverseWords(string s)
    {
        stack<string> st;
        
        for(int i=0;i<s.length();i++)
        {
            string word;
            if(s[i]==' ')
                continue;
            while(i<s.size() && s[i]!=' ')
            {
                word+=s[i];
                i++;
            }
            st.push(word);    
        }
        string b="";
        while(!st.empty())
        {
            b=b+st.top();
            st.pop();
            if(!st.empty())
                b=b+" ";
        }
        return b;
        
    }
};