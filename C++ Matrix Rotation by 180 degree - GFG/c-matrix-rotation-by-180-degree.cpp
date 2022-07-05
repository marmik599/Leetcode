// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) 
    {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            int l=0;
            int h=n-1;
            while(l<h)
            {
                swap(matrix[l][i],matrix[h][i]);
                l++;
                h--;
            }
        }
        for(int i=0;i<n;i++)
        {
            int l=0;
            int h=n-1;
            while(l<h)
            {
                swap(matrix[i][l],matrix[i][h]);
                l++;
                h--;
            }
        }
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.rotate(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends