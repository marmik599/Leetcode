// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}

// } Driver Code Ends

struct Node
{
    Node* links[26];
    
    
    bool containskey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
   
};
/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    int count=0;
    Node* root=new Node();
    
    for(int i=0;i<s.size();i++)
    {
        Node* node=root;
        for(int j=i;j<s.size();j++)
        {
            if(!node->containskey(s[j]))
            {
                count++;
                node->put(s[j],new Node());
            }
            node=node->get(s[j]);
        }
    }
    return count+1;
    
}