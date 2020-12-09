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
void Inorder(Node* root){
    // Base̥ case
    if(!root) return;

    // Left
    Inorder(root->left);
    
    // Node Process
    cout<<root->data<<" ";

    // Right
    Inorder(root->right);
}


void IterativeInorder(Node* root){

    stack<Node*> s;
    Node* curr = root;

    while(!s.empty()  || curr != NULL){

        if(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }

        else{

            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr = curr->right; 

        }
    }
}

int main(){

    av();
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    IterativeInorder(root);
        return 0;

}