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
Node* lca(Node* root ,int n1 ,int n2 )
{   
    // Base case
    if(!root) return NULL;
    
    // if either come in the path 
    if(root->data == n1 || root->data == n2) return root;
    
    Node* left = lca(root->left,n1,n2);
    Node* right = lca(root->right,n1,n2);
    
    // n1 and n2 are present in left and right then root is the answer
    /*
            1
           / \
          2   3
    */
    if(left && right) return root;
    
    // else ans can be from left or right
    
    if(left) return left;
    if(right) return right;
    
    // Return NUll lca not present
    return NULL;
}

int Dist(Node* lca, int ele,int dis){

    if(!lca) return 0;

    if(lca->data == ele) return dis;

    int ldist = Dist(lca->left,ele,dis+1);
    int rdist = Dist(lca->right,ele,dis+1);

    return max(ldist,rdist);
}

int findDist(Node* root, int a, int b){

    if(!root) return 0;

    // Find the lca of a and b first
    Node* LCA = lca(root,a,b);

    // dist is  = dis(lca,a) + dis(lca,b);
    int dist = Dist(LCA,a,0) + Dist(LCA,b,0);

    return dist;
}


int main()
{
    av();
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);
    
    int x = findDist(root,2,1);

    cout<<"Dist :"<<x<<endl;

    return 0;
}