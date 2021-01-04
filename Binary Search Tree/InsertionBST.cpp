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

Node* insert(Node* root, int Key)
{
    // If we found the null root to put the key
    if(!root){
        Node* newRoot = new Node(Key);
        return newRoot;
    }
    
    // duplication data case
    if(root->data == Key) return root;
    
    // if key is smaller than root data
    if(Key < root->data){
        root->left = insert(root->left,Key);
    }
    // if key is bigger than root data
    if(Key > root->data) 
        root->right = insert(root->right,Key);

    // finallty after the insertion return the root 
    return root;
}
