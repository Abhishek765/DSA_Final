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

Node* LCA(Node *root, int n1, int n2)
{
    // Base 
   if(!root) return NULL;
//    when both lies on left part
   if(n1 < root->data && n2 < root->data){
       return LCA(root->left, n1,n2);
   }

//    when both lies on left part
   if(n1 > root->data && n2 > root->data){
       return LCA(root->right, n1,n2);
   }
   
//    Other wise root is lca handles the two cases:
        // when either of them is root->means root is lca
        // else one is on left and one is on right>means root is lca
   return root;
}