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

void leftBoundary(Node *root, vector<int> &ans)
{
    if (!root) return;

    // Preorder
    if(root->left || root->right){
        ans.push_back(root->data);
    }

    if (root->left) leftBoundary(root->left, ans); 
    else if (root->right) leftBoundary(root->right, ans); 

}
void Leaf(Node *root, vector<int> &ans)
{
    if(!root) return;

    // Inorder Traversal
    Leaf(root->left, ans);
    // if leaf encounters
    if(!root->left && !root->right)
        ans.push_back(root->data);

    Leaf(root->right, ans);
    
}
void rightBoundary(Node *root, vector<int> &ans)
{
    if (!root) return;

    if (root->right) rightBoundary(root->right, ans);
    else if (root->left) rightBoundary(root->left, ans); 

    if(root->left || root->right){
        ans.push_back(root->data);
    }
} 
vector<int> printBoundary(Node *root)
{
    vector<int> ans;
    if(!root) return ans;
    // pushing the root element
    ans.push_back(root->data);

    // if root is leaf node
    if(!root->left && !root->right)
        return ans; 


    //  Left boundary
    leftBoundary(root->left, ans);
    //  Leaf
    Leaf(root, ans);
    //  Right boundary
    rightBoundary(root->right, ans);

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

    vector<int> ans = printBoundary(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}