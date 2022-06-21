// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
void createmapping(int in[],map<int,int> &inorder,int n)
    {
       
        for(int i=0;i<n;i++)
        {
            inorder[in[i]]=i;
        }
        
    }
    
    Node* solve(int in[],int pre[],int &index,int inorderst,int inorderend,map<int,int> &inorder,int n)
    {
        if(index<0 || inorderst>inorderend)
            return NULL;
        
        int element=pre[index--];    
        Node* root=new Node(element);
        
        int pos=inorder[element];
        
        root->right=solve(in,pre,index,pos+1,inorderend,inorder,n);
        root->left=solve(in,pre,index,inorderst,pos-1,inorder,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex=n-1;
        map<int,int> indorder;
        createmapping(in,indorder,n);
        Node* ans=solve(in,pre,preorderindex,0,n-1,indorder,n);
        return ans;
    }