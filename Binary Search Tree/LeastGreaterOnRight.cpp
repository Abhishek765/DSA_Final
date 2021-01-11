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

void justBigger(Node*& root, int data, Node*& succ){

    // Create the Tree
    if(!root) root = new Node(data);

    // Condition when root can be our succ
    // Because we want just bigger element so update the succ with root and move left subtree 
    if(data < root->data){
        succ = root;
        justBigger(root->left,data,succ);

    }
    else if(data > root->data){
        justBigger(root->right,data,succ);
    }

}
void inorderSucc(int a[],int n){

    // root of the BST
    Node* root = NULL;
    for(int i=n-1; i>=0; i--){

          Node* succ = NULL;
          
        // Finding the Just Bigger number than a[i]
          justBigger(root,a[i],succ);

          if(succ){
              a[i] = succ->data;
          }  
          else{
              a[i] = -1;
          }

    }
}
int main(){

    av();
     int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92,
                  43, 3, 91, 93, 25, 80, 28 };
    int n = sizeof(arr)/ sizeof(arr[0]);

    inorderSucc(arr,n);

    // Print the Inorder Successor
    for(auto i: arr){
        cout<<i<<" ";
    }
}