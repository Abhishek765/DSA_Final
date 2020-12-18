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

void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int largestSubtreeSum(Node * root,int& max_sum){

        if(!root) return 0;
        // Calculating max Sum from left and right sub tree
        int lsum = largestSubtreeSum(root->left,max_sum);
        int rsum = largestSubtreeSum(root->right,max_sum);
        // root sum 
        int curr_sum  = root->data + lsum + rsum;
        // Updating the max_sum
        max_sum = max(max_sum,curr_sum);

        return curr_sum;
}

int main(){
    av();
    Node* root = new Node(1); 
    root->left = new Node(-2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(-6); 
    root->right->right = new Node(2);
    int max_sum = INT_MIN;
    int curr_sum  = largestSubtreeSum(root,max_sum);

    cout<<max_sum<<endl;
}