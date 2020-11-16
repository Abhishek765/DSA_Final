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

int Height(Node* root){
    
    if(!root) return 0;
    
    return 1 + max(Height(root->left),Height(root->right));
    
}