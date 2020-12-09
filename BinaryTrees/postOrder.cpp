#include <bits/stdc++.h>
using namespace std;

void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// Recursive
void PostOrder(Node *root)
{
    // Base̥ case
    if (!root)
        return;

    // Left
    PostOrder(root->left);

    // Right
    PostOrder(root->right);

    // Node Process
    cout << root->data << " ";
}

void IterativePostOrder(Node *root)
{

    stack<Node *> s;
    s.push(root);
    stack<int> out;

    while (!s.empty())
    {

        Node *curr = s.top();
        s.pop();
        out.push(curr->data);
        // Push left
        if (curr->left)
            s.push(curr->left);

        // Push right
        if (curr->right)
            s.push(curr->right);
    }

    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}

int main()
{

    av();
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    IterativePostOrder(root);
    return 0;
}