// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */

int pallen(Node* h1,Node* h2)
{
    int length=0;
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data==h2->data)
            length++;
        else
            break;
            
        h1=h1->next;
        h2=h2->next;
    }
    return length;
}
int maxPalindrome(Node *head)
{
    int ans=0;
    Node* curr=head;
    Node* nex=curr->next;
    Node* prev=NULL;
    
    while(curr)
    {
        nex=curr->next;
        curr->next=prev;
        ans=max(ans,2*pallen(prev,nex)+1);
        ans=max(ans,2*pallen(curr,nex));
        prev=curr;
        curr=nex;
    }
    return ans;
}