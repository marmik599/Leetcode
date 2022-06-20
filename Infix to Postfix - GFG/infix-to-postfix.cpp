// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c)
    {
       if(c=='^')
        return 3;
        
        else if(c=='*' || c=='/')
        return 2;
        
        else if(c=='+' || c=='-')
            return 1;
        else
        return -1;
            
    }
    string infixToPostfix(string s) 
    {
        string ans;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(iswalnum(c))
            {
                ans.push_back(c);
            }
            else if(c=='(')
            {
                st.push(c);
            }
            else if(c==')')
            {
                while(st.top()!='(')
                {
                    char t=st.top();
                    st.pop();
                    ans.push_back(t);
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && prec(c)<=prec(st.top()))
                {
                    if(c=='^' && st.top()=='^')
                        break;
                    else
                    {
                        ans.push_back(st.top());
                        st.pop();
                    }
                }
                st.push(c);
            }
        }
        while(!st.empty())
        {
            char t=st.top();
            st.pop();
            ans.push_back(t);
        }
        return ans;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends