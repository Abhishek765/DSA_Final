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

void pushEleTillLeft(Node* root, stack<Node*>& s){
    
    if(!root) return;
    
    while(root){
        s.push(root);
        root = root->left;
    }
}
vector<int> merge(Node *root1, Node *root2)
{
        
        
        vector<int> ans;
        stack<Node*> s1,s2;
        
        //Initially push the elements in stacks till leftmost
        pushEleTillLeft(root1, s1);
        pushEleTillLeft(root2, s2);
        
        while(!s1.empty() && !s2.empty()){
            // If s1 top is small then push that into ans and 
            // push the Right se leftMost elements in s1
            if(s1.top()->data < s2.top()->data){
                Node* temp = s1.top();
                ans.push_back(temp->data);
                s1.pop();
                pushEleTillLeft(temp->right,s1);
            }
            // If s2 top is small then push that into ans and 
            // push the Right se leftMost elements in s2
            else if(s1.top()->data > s2.top()->data){
                Node* temp = s2.top();
                ans.push_back(temp->data);
                s2.pop();
                pushEleTillLeft(temp->right,s2);
            }
            else{
                // case when s1.top() == s2.top()
                Node* temp1 = s1.top();
                Node* temp2 = s2.top();
                
                // This is only applicable when duplication in ans is allowed
                ans.push_back(temp1->data);
                ans.push_back(temp2->data);
                // Pop from both and push right se leftmost in both
                s1.pop();
                s2.pop();
                pushEleTillLeft(temp1->right,s1);
                pushEleTillLeft(temp2->right,s2);
            }
            
            // s1 is there and s2 is not
            if(!s1.empty() && s2.empty()){
                // DO the iterative inorder in s1
                while(!s1.empty()){
                    Node* temp = s1.top();
                    ans.push_back(temp->data);
                    s1.pop();
                    // push right se leftmost if any 
                    pushEleTillLeft(temp->right,s1);
                }
            }
            else if(s1.empty() && !s2.empty()){
                // DO the iterative inorder in s2
                while(!s2.empty()){
                    Node* temp = s2.top();
                    ans.push_back(temp->data);
                    s2.pop();
                    // push right se leftmost if any 
                    pushEleTillLeft(temp->right,s2);
                }
            }
        }
        
        return ans;
}
int main() 
{ 
    av();
    /* Let us create the following tree as first tree 
         3 
        / \ 
        1 5 
    */
    Node * root1 = new Node(3); 
    root1->left = new Node(1); 
    root1->right = new Node(5); 
 
    /* Let us create the following tree as second tree 
         4 
        / \ 
        2 6 
    */
    Node * root2 = new Node(4); 
    root2->left = new Node(2); 
    root2->right = new Node(6); 
 
    // Print sorted nodes of both trees 
    vector<int> ans = merge(root1, root2); 

    for(auto i: ans){
        cout<<i<<" ";
    }
 
    return 0; 
}
