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

Node* BuildTree(int pre[], int& start,unordered_map<int,int> m, int inS,int inE){
    
    // if no element present
    if(inS > inE) return NULL;
    
    // Perform the preorder
    // Node creation from preorder
    Node* root = new Node(pre[start]);
    
    if(inS == inE) return root;
    
    // finding the position(index) of root node in inorder[] using map
    int mid = m[root->data];
    // Move to next element in preorder
    start++;


     // Left subtree
    root->left = BuildTree(pre,start,m,inS,mid-1);
    
    // right subtree
    root->right = BuildTree(pre,start,m,mid+1,inE);
    
    // return the root
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    // TO denote the element from preorder
    int start = 0;
    // start and end position of inorder
    int inS=0, inE = n-1;
    
    // Map to store the indexes of elements from inorder
    unordered_map<int,int> m;
    
    // storing the index corresponding to element 
    for(int i=inS;i<=inE;i++){
        m[in[i]] = i;
    }
    
    Node* root = BuildTree(pre,start,m,inS,inE);
    return root;
    
}

void postOrder(Node* root){

    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);

    cout<<root->data<<" ";
}

int main(){
//     5
// 10 1 30 40 20
// 1 10 20 30 40
av();
    int n = 5;
    int in[] = {10,1,30,40,20};
    int pre[] = {1,10,20,30,40};

    Node* root = buildTree(in,pre,n);

    postOrder(root);


}