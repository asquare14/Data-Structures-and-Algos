// https://leetcode.com/problems/diameter-of-binary-tree/
#include<bits/stdc++.h> 
using namespace std; 
  
// A BT Node 
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
int height(Node* node,int &res)
{
    if (node == NULL)  
        return 0;           
    int lheight = height(node->left,res);  
    int rheight = height(node->right,res);  
    res = max(res,lheight+rheight);
    return max(lheight,rheight)+1;
}
int diameter(Node* node)  
{  
   int res = 0;
   height(root,res);
   return res;
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

    cout<<diameter(root);
    return 0; 
} 