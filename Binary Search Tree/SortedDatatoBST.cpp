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

// Since the arr is sorted its middle is our root
Node* arrToBST(int arr[], int l,int r){

    // Base case when l crossed r
    if(l>r) return NULL;

    // find the mid which will be our root
    int mid = l + (r - l)/2;
    // create the node with value of mid
    Node* root = new Node(arr[mid]);

    // go to left and right and create the tree
   root->left = arrToBST(arr,l,mid-1);
   root->right = arrToBST(arr,mid+1,r);

    //    finally return the root
    return root;

}