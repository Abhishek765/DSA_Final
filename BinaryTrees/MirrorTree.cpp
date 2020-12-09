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

bool checkMirror(Node* root1, Node* root2){

    // Empty trees are mirror trees
    if(!root1 && !root2) return true;

    // If either root is not present then not a mirror tree
    if(!root1 || !root2) return false;

    // data of both root element must be same
    if(root1->data == root2->data) return true;

    // check for subtrees 
    return checkMirror(root1-> left, root2-> right) && checkMirror(root1-> right, root2-> left);
}