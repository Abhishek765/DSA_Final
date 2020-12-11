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

int isSumTree(Node* root,bool& flag){
    // base condition
    if(!root) return 0; 
    
    // if leaf encounters then sum is its value itself
    if(!root->left && !root->right)
        return root->data;
        
    // Calculate leftsum and rightsum
    int lsum = isSumTree(root->left,flag);
    int rsum = isSumTree(root->right,flag);

    // If root value != lsum + rsum
    if(root->data != lsum + rsum) flag = false;
      
    // total sum
    return (root->data + lsum + rsum);
 
 }

int main()
{
    av();
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);

    bool flag = true;
    
    int sum = isSumTree(root,flag);

    if(flag == true){
        cout<<"Is sumtree: "<<endl;
    }
    else
        cout<<"Is not a sumtree: "<<endl;

    return 0;
}