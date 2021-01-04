// ! Time : O(h)
// ! Space: O(1) no extra space
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int x)
    {
        key = x;
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

Node* justSmallerEle(Node* root){
    
    while(root->right)
        root = root->right;
    return root;
}
Node* justBiggerEle(Node* root){
    
    while(root->left)
        root = root->left;
    return root;
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(!root) return;
    
    // if key found at root
    if(root->key == key){
        // Predecessor will be just smaller than key and successor will be just bigger than key
        
        if(root->left)
            pre = justSmallerEle(root->left);
        
        
        if(root->right)
            suc = justBiggerEle(root->right);
    }
    
    // when root is > than key
    // Update suc and move to leftsubtree
   else if(root->key > key){
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    
    else{
        // when root is < than key
        // Update pre and move to rightsubtree 
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    
}