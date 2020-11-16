#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node*  left;
    struct Node*  right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


int Height(Node* root, int& d){
    
    if(!root) return 0;
    
    int lh = Height(root->left, d);
    int rh = Height(root->right, d);

    d= max(d, 1 + lh + rh);
    
    return 1 + max(lh,rh);
}
/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    int d= 0;
    
    int height = Height(node,d);
    return d;
}