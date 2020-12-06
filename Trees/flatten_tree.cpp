#include<bits/stdc++.h> 
using namespace std; 
  
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/solution/
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
Node* flattenWorker(Node* root) {
    if (root == nullptr) {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
        return root;
    TreeNode* l = flattenWorker(root->left);
    TreeNode* r = flattenWorker(root->right);
    if(l)
    {
        l->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    return r == NULL ? l :r;
}
// Greedily Change the Pointers
void  flattenWorkerIterative(Node* root)
{
        if (root == nullptr) {
            return;
        }
        
        TreeNode* node = root;
        
        while (node != nullptr) {
            
            // If the node has a left child
            if (node->left != nullptr) {
                
                // Find the rightmost node
                TreeNode* rightmost = node->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                
                // rewire the connections
                rightmost->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            
            // move on to the right side of the tree
            node = node->right;
        }
}
void flatten(Node* root)
{
    // Recursive, O(N) time , O(N) space
    flattenWorker(root);
    // Iterative O(n) time, O(1) space
    flattenWorkerIterative(root);
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