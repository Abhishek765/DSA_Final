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
void morrisInorderTraversal(Node* root){
    Node* curr = root;
    // Storing the current node
    while(curr != NULL){

        // if left is NULL
        if(curr->left == NULL){

            // Process the node and move to rigth
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        // Left is not Null
        else{
            //  Storing left in prev
             Node* prev = curr->left;
            // Go to left-RightMost
            // Stop either prev right is null or prev right is curr
            while(prev->right && prev->right != curr){

                prev = prev->right;
            }
            // when right most is not link with curr
            if(prev->right == NULL){
                // Make the link with curr and move the curr to left
                prev->right = curr;
                curr = curr->left;                
            }
            else{
                // If link already exists
                // Process the node break the link and move the curr to right
                cout<<curr->data << " ";
                prev->right = NULL;
                curr = curr->right;
            }

        }
    }
}

int main() 
{ 
    av();
    /* Let us create following BST 
                  50 
               /     \ 
              30      70 
             /  \    /  \ 
           20   40  60   80 */
    
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    cout<<"Inorder Traversal Using MorrisTraversal in O(1) space:\n";
    morrisInorderTraversal(root);
    return 0; 
} 

