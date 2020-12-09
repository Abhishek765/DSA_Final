#include<bits/stdc++.h>
using namespace std;


void av()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
struct Node{
    int data;
    Node * left;
    Node * right;

    Node(int x){
        data = x;
        left = right = NULL;
    }

};
// Recursive 
void PreOrder(Node* root){
    // Base̥ case
    if(!root) return;

    // Node Process
    cout<<root->data<<" ";
    
    // Left
    PreOrder(root->left);
    

    // Right
    PreOrder(root->right);
}


void IterativePreOrder(Node* root){

    stack<Node*> s;
    s.push(root);

    while(!s.empty()){

        Node* curr = s.top();
        s.pop();
        // Node
        cout<<curr->data<<" ";

        // Push right 
        if(curr->right)
            s.push(curr->right);
        
        // Push left 
        if(curr->left)
            s.push(curr->left);

    }
}

int main(){

    av();
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    IterativePreOrder(root);
    return 0;
}