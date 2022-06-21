// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    void createmapping(int in[],map<int,int> &inorder,int n)
    {
       
        for(int i=0;i<n;i++)
        {
            inorder[in[i]]=i;
        }
        
    }
    
    Node* solve(int in[],int pre[],int &index,int inorderst,int inorderend,map<int,int> &inorder,int n)
    {
        if(index>=n || inorderst>inorderend)
            return NULL;
        
        int element=pre[index++];    
        Node* root=new Node(element);
        
        int pos=inorder[element];
        root->left=solve(in,pre,index,inorderst,pos-1,inorder,n);
        root->right=solve(in,pre,index,pos+1,inorderend,inorder,n);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex=0;
        map<int,int> indorder;
        createmapping(in,indorder,n);
        Node* ans=solve(in,pre,preorderindex,0,n-1,indorder,n);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends