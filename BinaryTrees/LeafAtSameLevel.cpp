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
bool checkLevel(Node* root,int level, int& leafLevel){
    
    if(!root) return true;
    
    // Leaf encounter
    if(!root->left && !root->right){
        
        // if leaf encounter first time
        if(leafLevel == 0){
            leafLevel = level;
            return true;
        }
        
        // next time leaf encounters then check the level
            return leafLevel == level;
    }
    
    return (checkLevel(root->left,level+1, leafLevel) && checkLevel(root->right,level+1, leafLevel));
}

bool check(Node *root)
{   
    int level = 0, leafLevel=0;
    return checkLevel(root,level,leafLevel);
    
}

int main() 
{ 
    av();
    Node *root = new Node(12); 
    root->left = new Node(5); 
    root->left->left = new Node(3); 
    root->left->right = new Node(9); 
    root->left->left->left = new Node(1); 
    root->left->right->left = new Node(1); 
  

   cout<< check(root); 
  
    return 0; 
}