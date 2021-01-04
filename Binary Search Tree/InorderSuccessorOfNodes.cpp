#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right,*next;

    node(int x)
    {
        data = x;
        left = right = next = NULL;
    }
};
void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void nextSucc(struct node* root, struct node*& suc){
    
    // Now reverse Inorder 
    if(root){
    nextSucc(root->right,suc);
    
    // Putting the current
    root->next = suc;
    // Updating the successor with previous greater
    suc = root;
    
    nextSucc(root->left,suc);
    }
    
}
void populateNext(struct node* p)
{
//   Initially store the rightmost element successor i.e NULL
    struct node* suc = NULL;
    
    nextSucc(p,suc);
}