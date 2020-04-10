#include<bits/stdc++.h> 
using namespace std; 
  
// A BT Node 
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
void levelorder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    int nodeCount = q.size();  
    while(q.empty()==false)
    {
        int nodeCount = q.size(); 
        while(nodeCount>0)
        {
                    Node* t = q.front();
                    q.pop();
                    cout<<t->data<<" ";
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                    nodeCount--;
        }
        cout<<endl;
    }
}
// Utility function to create new Node 
Node *newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 
  
// Driver program 
int main() 
{ 
    // Let us construct the Tree shown in the above figure 
    Node *root     = newNode(1); 
    root->left     = newNode(2); 
    root->right     = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);

    cout<<"Level-order:"<<" ";
    levelorder(root);
    cout<<endl;
    return 0; 
} 