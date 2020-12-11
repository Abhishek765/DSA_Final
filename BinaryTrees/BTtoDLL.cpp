#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void BTtoDLL(Node* root, Node*& head, Node*& tail){

    if(!root) return;

    // Inorder
    // Left
    BTtoDLL(root->left, head, tail);
    
    //Process the node
    // if head is NULL means LL is not made yet
    if(!head){
        head = root;
        // tail = root;
    } 
    else{
    // LL is present
    root->left = tail;
    tail->right = root;
    // tail = root;

    }
    tail = root;

    // Right
    BTtoDLL(root->right, head, tail);
}

Node * bToDLL(Node *root)
{
    if(!root) return NULL;
    Node* head = NULL;
    Node* tail = NULL;
    BTtoDLL(root, head,tail);

    return head;

}


void printList(Node* head){

    // To handle prev node
    Node* prev = NULL;

    while(head != NULL){
        cout<<head->data<<" ";
        prev = head;
        head = head->right;
    }
    cout<<endl;

}



int main()
{
    av();
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(4);

    Node* head = bToDLL(root);
    printList(head);
    return 0;
}