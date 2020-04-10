#include<bits/stdc++.h> 
using namespace std; 

//implement insert, delete, reverse// A simple CPP program to introduce 
// a linked list 
#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node* next; 
}; 

void printLinkedList(Node* head)
{
    Node* root = head;
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->next;
    }
    cout<<endl;
}
void insert(Node* head, int val)
{
    Node* root = head;
    while(root->next!=NULL)
    {
        root=root->next;
    }
    
    Node* newNode = new Node();
    newNode->next = NULL;
    newNode->data = val;
    root->next = newNode;
}

void deleteNthNode(Node* head, int n)
{
        int len = 0;
        Node* node = head;
        Node* t = head;
        Node* prev = NULL;
        Node* nxt = NULL;
        
        while(t!=NULL)
        {
            len++;
            t= t->next;
        }
        
        if(len==n-1) head=head->next;
        else
        {
             int j = n-1;
        
            while(node->next!=NULL)
            {
                 prev = node;
                 node = node->next;
                 nxt = node->next;
                 j--;
                if(j==0)
                {
                    prev->next = nxt;
                    node->next = NULL;
                }
            }
        }
}
void reverse(Node** head)
{
	Node* result = NULL;
	Node* current = *head;

	while (current != NULL)
	{
		Node* next = current->next;

		current->next = result;
		result = current;
		current = next;
	}

	// fix head pointer
	*head = result;
}
  
int main() 
{ 
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 
   
    head = new Node(); 
    second = new Node(); 
    third = new Node(); 

    head->data = 1;  
    head->next = second; 
    second->data = 2; 
  
    second->next = third; 

    third->data = 3;  
    third->next = NULL; 
    insert(head,4);
    //deleteNthNode(head,2);
    printLinkedList(head);
    cout<<"Reversed Linked List:"<<endl;
    reverse(&head);
    printLinkedList(head);
    return 0; 
} 