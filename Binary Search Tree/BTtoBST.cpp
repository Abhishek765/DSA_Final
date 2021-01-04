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

void replaceValue(Node* root, vector<int> v, int& curr){
    
    if(!root) return;
    
    replaceValue(root->left, v,curr);
    
    root->data = v[curr++];
    
    replaceValue(root->right, v, curr);
}
void retrieve(Node* root, vector<int>& v){
    
    if(!root) return;
    
    retrieve(root->left, v);
    
    v.push_back(root->data);
    
    retrieve(root->right, v);
}
// The given root is the root of the Binary Tree
// Return the root of the generated BST
Node *binaryTreeToBST (Node *root)
{
    vector<int> v;
    // Inorder to retrieve the data from BT
    retrieve(root,v);
    
    sort(v.begin(), v.end());
    
    // Do inorder traversal in BST and replace the value of node using vector
    int curr = 0;
    replaceValue(root, v, curr);
    
    return root;
}