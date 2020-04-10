#include<bits/stdc++.h> 
using namespace std; 
  
// A BT Node 
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 

int height(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
    
        int lheight = height(node->left);  
        int rheight = height(node->right);  
  
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
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

    cout<<height(root);
    return 0; 
} 