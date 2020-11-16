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
}
vector<int> levelOrder(Node* node)
{
    vector<int> v;
    queue<Node*> q;
    
    if(!node) return v;
    
    q.push(node);
    
    while(!q.empty()){
        
        Node* temp = q.front();
        q.pop();
        
        v.push_back(temp->data);
        
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    
    return v;
  
}