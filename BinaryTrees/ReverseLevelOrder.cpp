#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node*  left;
    struct Node*  right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> v;
    
    if(!root) return v;

    queue<Node*> q;
    stack<int> s;
    
    q.push(root);

    
    while(!q.empty()){
        
        Node* temp = q.front();
        s.push(temp->data);
        q.pop();
        
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
        
    }
    
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    
    return v;
    
}