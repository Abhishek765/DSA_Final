// ! Time is O(n) and Space is O(1)
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
int morrisInorderTraversal(Node* root){
    int count=0;
    Node* curr = root;
    // Storing the current node
    while(curr != NULL){

        // if left is NULL
        if(curr->left == NULL){

            // Process the node and move to rigth
            count++;
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
                count++;
                prev->right = NULL;
                curr = curr->right;
            }

        }
    }
    return count;
}
int findMedian(Node* root){
    
    int currCount = 0;
    int morrisCount = morrisInorderTraversal(root);

    // Morris Traversal to check the count
    Node* curr = root,*prev;
    while(curr != NULL){
        // left is not present
        if(curr->left == NULL){

            // Process the node and move to right
            currCount++;

            // check if morrisCount is odd 
            // then middle is at (morrisCount+1)/2
            if(morrisCount%2 != 0 && currCount == (morrisCount+1)/2)
                return prev->data;

            // else check MorrisCount is even
            // check for second middle element which is at (morrisCount/2 + 1)
            // return average of prev and curr data;
            else if(morrisCount%2 == 0 && currCount == (morrisCount/2) + 1)
                return (prev->data + curr->data)/2;

            // track the previous node for finding th median 

            prev = curr;    
            
            curr = curr->right;



        }
        else{
            // Left is present then go to left's rightmost

            Node* temp = curr->left;

            // Move to right until found null and link is present
            while(temp->right != NULL && temp->right != curr)
                temp = temp->right;

            // If exit due to NULL occurence
            // Make the link with curr
            if(temp->right == NULL){
                temp->right = curr;
                curr= curr->left;
            }
            // Already Link present
            else{
                // Process the node , break the link and go to right
                temp->right = NULL;
                prev = temp;
                currCount++;
                // if My MorrisCount is odd then curr is Middle
                if(morrisCount%2 != 0 && currCount == (morrisCount+1)/2)
                    return curr->data;

                // else check MorrisCount is even
                // check for second middle element which is at (morrisCount/2 + 1)
                // return average of prev and curr data;
                else if(morrisCount%2 == 0 && currCount == (morrisCount/2) + 1)
                    return (prev->data + curr->data)/2;
                    
                    prev = curr;
                    curr= curr->right;
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
           20   40  60   80
                           \ 
                            90*/
    
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    root->right->right->right = new Node(90);
    cout << "\nMedian of BST is "
         << findMedian(root);
    return 0; 
} 

