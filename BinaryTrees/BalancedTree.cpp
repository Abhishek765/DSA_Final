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

int Height(Node *root,bool& isBalanced)
{

    if (!root)
        return 0;

    int lh = Height(root->left,isBalanced);
    int rh = Height(root->right,isBalanced);
    // either lh = rh+1 or rh = lh+1 then tree is not balanced
    if(abs(lh - rh) > 1) isBalanced = false;

    return 1 + max(lh,rh);
}

bool isBalanced(Node *root)
{
    bool isBalanced = true;
    int h = Height(root,isBalanced);
    return isBalanced;
}