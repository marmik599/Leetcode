// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
     bool cycleHai(int node, vector<bool> &visited, vector<bool> &dfsVisited, unordered_map<int, list<int>> &adj) {
        
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto i: adj[node]) {
            if(!visited[i]) {
                if(cycleHai(i, visited, dfsVisited, adj)) {
                    return true;
                }
            }
            else if(dfsVisited[i]) {
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
        
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    unordered_map<int, list<int>> adj;
	    
	    for(int i = 0; i < prerequisites.size(); i++) {
	        int child = prerequisites[i].first;
	        int parent = prerequisites[i].second;
	        
	        adj[parent].push_back(child);
	    }
	    
	    vector<bool> visited(N, false);
	    vector<bool> dfsVisited(N, false);
	    bool flag = false;
	    
	    for(int i = 0; i < N; i++) {
	        if(!visited[i]) {
	            if(cycleHai(i, visited, dfsVisited, adj)) {
	                flag = true;
	            }
	        }
	    }
	   
	    
	    if(flag == true) {
	        return false;
	    }
	    
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends