#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = right  = NULL;
    }
};
void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> leftView(Node *root)
{
    vector<int> ans;

    if(!root) return ans;

    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    bool isFirst = true;

    while(!q.empty()){
        Node *temp = q.front();

        // if our temp is NULL;
        if(!temp){
            q.pop();

            if(q.size() == 0) return ans;

            q.push(NULL);
            isFirst = true;
        }

        else{
            // we encounter the first element 
            if(isFirst){
                ans.push_back(temp->data);
                q.pop();
                // push left and right to the queue
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
               isFirst = false;
            }
            else{
                 q.pop();
                // push left and right to the queue
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

    }
    
    return ans;
}

int main(){
    av();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    vector<int> ans = leftView(root);

    for(auto i: ans){
        cout<<i<<" ";
    }
        return 0;
}