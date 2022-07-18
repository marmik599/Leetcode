/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
            //vector<Node*> level;
            for(int i=0;i<n;i++)
            {
                Node* temp=q.front();
                q.pop();
                //level.push_back(temp);
                if(i!=n-1)
                    temp->next=q.front();
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
//             for(int i=1;i<level.size();i++)
//                 level[i-1]->next=level[i];
            
//             level[level.size()-1]->next=NULL;
        }
        return root;
    }
};