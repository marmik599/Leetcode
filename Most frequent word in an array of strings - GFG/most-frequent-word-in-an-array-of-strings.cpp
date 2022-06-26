// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
struct node{
   int e=0;
   node *next[26]={NULL};
};
class trie{
   node *root;
   public:
   trie(){
       root=new node;
   }
   
   void insert(string &s){
       node *head=root;
       for(int i=0;i<s.size();i++){
           if(!head->next[s[i]-'a']) head->next[s[i]-'a']=new node;
           head=head->next[s[i]-'a'];
       }
       head->e++;
   }
   
   int freq(string &s){
       node *head=root;
       for(int i=0;i<s.size();i++)
           head=head->next[s[i]-'a'];
       return head->e;
   }
};
class Solution
{
   public:
   //Function to find most frequent word in an array of strings.
   string mostFrequentWord(string arr[], int n) 
   {
       trie *t=new trie();
       vector<string> v;
       unordered_set<string> us;
       for(int i=0;i<n;i++) t->insert(arr[i]);
       int m=0;
       for(int i=0;i<n;i++){
           if(us.find(arr[i])==us.end()){
               v.push_back(arr[i]);
               us.insert(arr[i]);
               m=max(m,t->freq(arr[i]));
           } 
       }
       stack<string> s;
       for(auto i:v) if(t->freq(i) == m) s.push(i);
       return s.top();
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends