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

string dubString(Node* root, unordered_set<string>& subtree){

    string s = "";

     
    // Serialization with preorder

    // When root is null add the marker
    if(!root) return s + "$";
    

    // left subtree
    string lstr = dubString(root->left,subtree);
    // If left part is empty
    if(lstr.compare("") == 0)
        return s;
    
    // Right subtree
    string rstr = dubString(root->right,subtree);
    // If right part is empty
    if(rstr.compare("") == 0)
        return s;
        
    // Serialization updating the s
    s = s + char(root->data)+ lstr + rstr;
    
    // after adding the marker tree height increase by 1
    // Checking whether s is already present in Set
    if(s.length()>3 && subtree.find(s) != subtree.end()){
        return "";
    }
    
    subtree.insert(s);
    
    return s;
}
bool dupSub(Node *root)
{
    if(!root) return false;
    
    unordered_set<string> subtree;
     string s = dubString(root,subtree);
     bool ans;
     
     (s.compare("") == 0 ) ? ans= true : ans= false;
     
     return ans;
}

int main() 
{ 
    av();
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->left->left = new Node(4); 
    root->left->right= new Node(5); 
    root->right = new Node(3);
    root->right->right = new Node(2);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(5);

  
    cout<< dupSub(root)<<endl; 
  
    return 0; 
}