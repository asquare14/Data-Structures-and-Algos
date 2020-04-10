#include<bits/stdc++.h> 
using namespace std; 
  
// A BT Node 
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
void flatten(Node* root)
{
    if(root==NULL || root->left==NULL || root->right==NULL)
    {
        return;
    }
    if(root->left!=NULL)
    {
        flatten(root->left);
        
        struct Node* tmpRight = root->right; 
        root->right = root->left; 
        root->left = NULL; 
        
        struct Node* t = root->right; 
        while (t->right != NULL) { 
            t = t->right; 
        } 
  
        t->right = tmpRight; 
    }
    flatten(root->right);
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
    flatten(root);
    cout<<endl;
    return 0; 
} 