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

vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    if(!root) return ans;
    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);

    // Loop till either stack is not empty
    while(!s1.empty() || !s2.empty()){

            while(!s1.empty()){

                Node* temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);
               
                // Push right and left
                if(temp->left) s2.push(temp->left);
                if(temp->right) s2.push(temp->right);
            }

            while(!s2.empty()){

                Node* temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);
                // Push right and left
                if(temp->right) s1.push(temp->right);
                if(temp->left) s1.push(temp->left);
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

    vector<int> ans = zigZagTraversal(root);

    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}