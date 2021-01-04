
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

bool checkBST(Node* root, int l, int r){
    
    if(!root) return true;
    if(l > r) return false;
    
    if(root->data < l || root->data > r) return false;
    
    return ((checkBST(root->left, l , root->data - 1)) && (checkBST(root->right, root->data + 1, r)));
}
// return true if the given tree is a BST, else return false
bool isBST(Node* root) {

    return checkBST(root, INT_MIN,INT_MAX);
}