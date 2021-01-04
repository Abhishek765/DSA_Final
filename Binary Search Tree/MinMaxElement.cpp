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

int minValue(Node* root)
{
    if(!root) return -1;
    
    while(root->left)
        root=root->left;
    return root->data;
}

int maxValue(Node* root)
{
    if(!root) return -1;
    
    while(root->right)
        root=root->right;
    return root->data;
}