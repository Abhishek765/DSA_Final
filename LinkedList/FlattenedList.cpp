
// ! Time: O(Number of Nodes) and Space is O(1)

#include <bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


// Merge two sorted list function
Node* mergeLists(Node* a, Node* b){
    
    // Creating a dummy node
    Node* temp = new Node(0);
    Node* mergedHead = temp; // mergedHead->bottom will be our new merged head 
    
    // applying mergesort kind in LL
    while(a != NULL && b != NULL){
        // merge a node and move a and temp both
        if(a->data < b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    
    // checking which one is not null
    if(a) temp->bottom = a;
    else
        temp->bottom  = b;
    
    // at last return mergedHead->bottom
    return mergedHead->bottom;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
//   Base case
    if(root == NULL || root->next == NULL)
        return root;
    
    // else call the recursive call till we reached the last node on right
    root->next = flatten(root->next);
    
    // merge root and root->next and store it in root
    root= mergeLists(root, root->next);
    
    // finally after merging return the merged head
    return root;

}