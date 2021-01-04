// !Time : O(h) h->height of the tree
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    TreeNode* nextJustSmall(TreeNode* root){
        
        while(root->right)
            root = root->right;
        
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return NULL;
        
        
        if(root->val == key){
            
//             if root contains 0 child -> leaf node
            if(!root->left && !root->right)
                return NULL;
            
//              if root contains 2 childs
            
            if(root->left && root->right){
//                 finding the just  next smaller element
                TreeNode* temp = nextJustSmall(root->left);
                // Update the root data with new value
                root->val = temp->val;
                // Delete that temp value from tree
                root->left = deleteNode(root->left,temp->val);
                // Return the tree After delete
                return root;
            }
            
            
//             if 1 child with optimization if only 1 child exists then we can return that 1 child and delete the root
            if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;            
                return temp;
            }   
            
             if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;            
                return temp;
            } 
            
        }
        
        else if(root->val < key){
//             Go to right side
            root->right = deleteNode(root->right, key);
        }
        
        else{
//             left side
            root->left = deleteNode(root->left, key);

        }
        
        return root;
    }
};