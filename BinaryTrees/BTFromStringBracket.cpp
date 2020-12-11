// Time complexity: O(n^2)
// space: O(n) -> stack

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

void preOrder(Node* root){
    if(!root) return;

    cout<<root->data<<" ";

    // left
    preOrder(root->left);
    // Right
    preOrder(root->right);
}
int findClosingIndex(string str, int low, int high){

    if(low > high) return -1;

    // to find matching bracket
    stack<char> s;

    // Traverse from opening bracket index to high
    for(int i=low; i<=high; i++){

        if(str[i] == '(')
            s.push(str[i]);

        else if(str[i] == ')'){
            // if stack top is "(" pop it
            if(s.top() == '('){
                s.pop();
                
                // if stack is empty we found the closing bracket index
                if(s.empty())
                    return i;

            }

        }   

    }

    return -1;
}
Node* treeFromString(string s, int low, int high){

        if(low > high) return NULL;

        // Create the root node
        Node* root = new Node(s[low] - '0');

        int index =-1;

        // if "(" encounters find the index of matching closing bracket
        if(low + 1 < high && s[low + 1] == '('){
            index = findClosingIndex(s,low + 1, high);
        }

        // if index is found
        if(index != -1){

                // Build left subtree
                root->left = treeFromString(s,low + 2, index - 1);
                
                // Build Right subtree
                root->right = treeFromString(s,index + 2,high - 1);
        }

        return root;
}


int main(){
    av();
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str, 0, str.length() - 1);
    preOrder(root);
}