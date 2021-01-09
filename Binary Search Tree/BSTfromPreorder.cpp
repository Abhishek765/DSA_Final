#include<bits/stdc++.h>
using namespace std;

struct Node{
    
    int data;
    Node *left, *right;

    Node(int x){
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

Node* ConstructBST(int pre[],int low,int high,int &currPos,int n){

    // base conditions
    // 1. size check
    if(currPos >= n) return NULL;

    int x = pre[currPos];
    // 2. Range check for currPos data must be in range
    if(x < low || x > high) return NULL;

    // 3. if My low > My high then [low,high] is invalid range
    if(low > high) return NULL;

    // else means curr data from arr is in range
    // Create the node 
    Node* root = new Node(pre[currPos]);
    currPos++;

    // Call the left subtree and Update the range
    root->left = ConstructBST(pre,low,x-1,currPos,n);

    // Call the Right subtree and update the range
    root->right = ConstructBST(pre,x+1,high,currPos,n);
    
    return root;

}

Node* ContrBST(int pre[],int n){

    int currPos = 0;
    return ConstructBST(pre,INT_MIN,INT_MAX,currPos,n);
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
int main(){

    av();
    int pre[] = {40,30,22,34,50,60,62,65};
    int n = 8;
    Node* root = ContrBST(pre, n);

    printInorder(root);
}