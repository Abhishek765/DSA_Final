#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

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
// Trees which are mirror or identical ar isomorphic
bool isIsomorphism(Node* root1, Node * root2){

    // Both are empty
    if(!root1 && !root2) return true;

    // Either one is empty then false
    if(!root1 || !root2) return false;

    // root data must be same
    if(root1->data != root2->data) return false;

    bool lmirr = isIsomorphism(root1->left, root2->right); 
    bool rmirr = isIsomorphism(root1->right, root2->left); 
    
    bool lIdentical = isIsomorphism(root1->left, root2->left); 
    bool rIdentical = isIsomorphism(root1->right, root2->right); 

    // Either tree is Mirror or Identical
    return (lmirr && rmirr) || (lIdentical && rIdentical);

}

int main(){
    av();
    // Tree 1
    Node *n1 = new Node(1); 
    n1->left        = new Node(2); 
    n1->right       = new Node(3); 
    n1->left->left  = new Node(4); 
    n1->left->right = new Node(5); 
    n1->right->left  = new Node(6); 
    n1->left->right->left = new Node(7); 
    n1->left->right->right = new Node(8); 
  
    // Tree 2
     Node *n2 = new Node(1); 
    n2->left         = new Node(3); 
    n2->right        = new Node(2); 
    n2->right->left   = new Node(4); 
    n2->right->right   = new Node(5); 
    n2->left->right   = new Node(6); 
    n2->right->right->left = new Node(8); 
    n2->right->right->right = new Node(7);

    (isIsomorphism(n1,n2)) ? cout<<"Yes\n" : cout<<"No\n";
    return 0;
}