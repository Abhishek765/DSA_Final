#include<bits/stdc++.h>
using namespace std;

struct Node{
    
    int data;
    Node *left, *right;

    Node(int x){
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
void countInRange(Node* root, int l, int r, int& count){
    
    if(!root) return;
    // When in range count it
    if(root->data >=l && root->data <= r)
        count++;

    if(l < root->data) 
        countInRange(root->left, l, r, count);
    
    if(r > root->data) 
        countInRange(root->right, l, r, count);
    
}
int getCountOfNode(Node *root, int l, int h)
{
    int count = 0;
    countInRange(root, l , h, count);
    return count;
}