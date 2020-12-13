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

// Printing the path
void printVector(vector<Node*> v, int i) 
{ 
    for (int j=i; j<v.size(); j++) 
        cout << v[j]->data << " "; 
    cout << endl; 
} 
void printpaths(Node* root,vector<Node*> v,int k){

    if(!root) return;

    // Preorder
    // Node 
    v.push_back(root);

    // left
    printpaths(root->left,v,k);
    
    // Right
    printpaths(root->right,v,k);

    // checking the sum from one branch
    // We want path from root that's why traversing the vector from back
    int sum=0;
    for(int i=v.size()-1;i>=0;i--){

        sum += v[i]->data;

        // found one path
        if(sum == k)
            printVector(v,i);

    }
}
void printKPath(Node* root, int k){

    // vector to store the paths
    vector<Node*> v;
    printpaths(root,v,k);
}

int main() 
{ 
    av();
    Node *root = new Node(1); 
    root->left = new Node(3); 
    root->left->left = new Node(2); 
    root->left->right = new Node(1); 
    root->left->right->left = new Node(1); 
    root->right = new Node(-1); 
    root->right->left = new Node(4); 
    root->right->left->left = new Node(1); 
    root->right->left->right = new Node(2); 
    root->right->right = new Node(5); 
    root->right->right->right = new Node(2); 
  
    int k = 5; 
    printKPath(root, k); 
  
    return 0; 
}