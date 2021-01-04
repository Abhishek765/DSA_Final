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

void KthSmallestIn(Node* root, int& k,int& ans){
    
    if(!root) return;
    if(k<=0) return;
    // Do the inorder go to the Leftmost node first
    KthSmallestIn(root->left,k,ans);
    k--;
    
    // Means we reach the Kth element
    if(k==0){
        ans = root->data    ;
        return;
    }
    
    KthSmallestIn(root->right,k,ans);
}
// return the Kth largest element in the given BST rooted at 'root'
int kthSmallest(Node *root, int K)
{
    int ans = -1;
    KthSmallestIn(root,K,ans);
    
    return ans;
}