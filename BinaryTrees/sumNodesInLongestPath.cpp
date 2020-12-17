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
void sumOfLongestPath(Node* root, int& size,int& maxSize,int& curr_sum,int& max_sum){
    
    if(!root) return;
    
    // else something is present tree is not empty
    size++;
    curr_sum += root->data;
    
    // if leaf encounters 
    if(!root->left && !root->right){
        
        // compare the size
        if(size > maxSize && curr_sum>=max_sum){
            // found new longest path update size and sum
            max_sum = curr_sum;
            maxSize = size;
        }
        // case when size is same compare the sum
        else if(size == maxSize && curr_sum>max_sum){
                max_sum = curr_sum;
        }
        
    }
    sumOfLongestPath(root->left,size,maxSize,curr_sum,max_sum);
    sumOfLongestPath(root->right,size,maxSize,curr_sum,max_sum);
    
    size--;
    curr_sum -= root->data;
    
    
}
int sumOfLongRootToLeafPath(Node* root)
{
	
	int size = 0;
	int maxSize = 0;
	int curr_sum =0;
	int max_sum =0;

    sumOfLongestPath(root, size,maxSize, curr_sum,max_sum);
    
    return max_sum;
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

  
    cout<< sumOfLongRootToLeafPath(root)<<endl; 
  
    return 0; 
}