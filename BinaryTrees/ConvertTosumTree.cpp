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

int sumTree(Node* root){
    // base condition
    if(!root) return 0; 
    
    // Calculate leftsum and rightsum
    int lsum = sumTree(root->left);
    int rsum = sumTree(root->right);
    
    // Store root total sum in temporary variable
    int tempVal = root->data + lsum + rsum;
    
    // Update the node sum
    root->data = lsum+rsum;
    
    // total sum
    return tempVal;
}
void toSumTree(Node *node)
{
    int sum = sumTree(node);
}

void preOrder(Node* root){

    if(!root) return;

    // node
    cout<<root->data<<" ";

    // Left
    preOrder(root->left);
    // Right
    preOrder(root->right);
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

    cout<<"Before: "<<endl;
    preOrder(root);
    cout<<"\n";
    
    toSumTree(root);

    cout<<"After: "<<endl;
    preOrder(root);

    return 0;
}