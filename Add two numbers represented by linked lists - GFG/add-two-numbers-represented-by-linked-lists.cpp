// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       Node* head1=reverse(first);
       Node* head2=reverse(second);
       
       if(head2==NULL)
        return head1;
        
        if(head1==NULL)
            return head2;
            
        int carry=0;
        Node* dummyhead= new Node(0);
        Node* head=dummyhead;
        while(head1 || head2 || carry)
        {
            int sum=0;
            if(head1!=NULL)
            {
                sum=sum+head1->data;
                head1=head1->next;
            }
            if(head2!=NULL)
            {
                sum=sum+head2->data;
                head2=head2->next;
            }
            sum=sum+carry;
            carry=sum/10;
            Node* newnode=new Node(sum%10);
            dummyhead->next=newnode;
            dummyhead=dummyhead->next;
            
        }
        Node *ans=reverse(head->next);
        return ans;
    }
    
    struct Node* reverse(Node* head)
    {
        if(head==NULL)
        return head;
        
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr)
        {
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends