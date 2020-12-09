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

void BottomView(Node *root)
{

    if (!root)
        return;

    map<int, int> m;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {

        pair<Node *, int> temp = q.front();
        q.pop();
        Node *curr = temp.first;
        int hd = temp.second;

        // If particular hd is free to occupy in map
        m[hd] = curr->data;

        // Pushing left and right
        if (curr->left)
            q.push({curr->left, hd - 1});
        if (curr->right)
            q.push({curr->right, hd + 1});
    }
    // Printing the elements top view
    for (auto it : m)
    {
        cout << it.second << " ";
    }
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

    BottomView(root);
    return 0;
}