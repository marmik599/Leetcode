// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x)
{
    Node* lt=new Node(0);
    Node* et=new Node(0);
    Node* gt=new Node(0);
    
    Node* lth=lt;
    Node* eth=et;
    Node* gth=gt;
        
    while(head!=NULL)
    {
        if(head->data < x)
        {
            lt->next=head;
            lt=lt->next;
        }
        else if(head->data==x)
        {
            et->next=head;
            et=et->next;
        }
        else
        {
            gt->next=head;
            gt=gt->next;
        }
        head=head->next;
    }
    lt->next=NULL;
    et->next-NULL;
    gt->next=NULL;
    
    if(eth->next!=NULL)
    {
        lt->next=eth->next;
        et->next=gth->next;
    }
    else
    {
        lt->next=gth->next;
    }
    return lth->next;
}