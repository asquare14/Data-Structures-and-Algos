#include<bits/stdc++.h> 
using namespace std; 
  
// A BT Node 
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
void postorder(Node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorder(Node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void inorder(Node* root)
{
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
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

    cout<<"Postorder:"<<" ";
    postorder(root);
    cout<<endl;
    
    cout<<"Preorder:"<<" ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder:"<<" ";
    inorder(root);
    cout<<endl;
    return 0; 
} 