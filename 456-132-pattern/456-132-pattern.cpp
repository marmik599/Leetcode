class Solution {
public:
    bool find132pattern(vector<int>& arr)
    {
       int n=arr.size();
        stack<int> s;
        int k=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<k)
                return true;
            else
            {
                while(!s.empty() && arr[i]>s.top())
                {
                    k=s.top();
                    s.pop();
                }
                s.push(arr[i]);
            }
        }
        return false;
    }
};