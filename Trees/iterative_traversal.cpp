#include<bits/stdc++.h> 
using namespace std; 
  
// A BT Node 
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
void dfs(Node* root)
{
    stack<Node*> s;
    s.push(root);
    while(s.empty()==false)
    {
        Node* t = s.top();
        s.pop();   
        if(t != NULL){
           // preorder
            cout<<t->data<<" ";
            s.push(t->right);
            s.push(t->left);
            
         }
    }   
}

void inorder(Node* root)
{
    stack<Node*> s;
    Node* t = root;
    while(s.empty()==false || t != NULL )
    {
            while(t!=NULL)
            {
                s.push(t);
                t=t->left;
            }
            t = s.top(); s.pop();
            cout << t->data << " ";
            t = t->right; 
    }   
    
}

void postorder(Node* root)
{
    if (root == NULL) 
        return; 
  
    stack<Node *> s1, s2; 
  
    s1.push(root); 
    Node* node; 
  
    // Run while first stack is not empty 
    while (!s1.empty()) { 
        // Pop an item from s1 and push it to s2 
        node = s1.top(); 
        s1.pop(); 
        s2.push(node); 
  
        // Push left and right children 
        // of removed item to s1 
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    } 
  
    // Print all elements of second stack 
    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        cout << node->data << " "; 
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

    cout<<"DFS/Pre-order:"<<" ";
    dfs(root);
    cout<<endl;
    
    cout<<"In-order:"<<" ";
    inorder(root);
    cout<<endl;

    cout<<"Post-order:"<<" ";
    postorder(root);
    cout<<endl;
    return 0; 
} 