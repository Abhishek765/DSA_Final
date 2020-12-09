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
void preorder(Node* root,map<int,vector<int>>& m,int hd){

    if(!root) return;
    // Pushing the root data
    m[hd].push_back(root->data);

    // left 
    preorder(root->left,m,hd+1);
    // Right 
    preorder(root->right,m,hd);

}
vector<int> diagonalTraversal(Node *root)
{
    vector<int> ans;
    map<int, vector<int>> m;
    int hd = 0;
    preorder(root,m,hd);

    for(auto i: m){
        // Traversing the vector
        for(auto j: i.second){
            ans.push_back(j);
        }
    }
    return ans;
}
int main()
{
    av();
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

   vector<int> ans = diagonalTraversal(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
       return 0;
}