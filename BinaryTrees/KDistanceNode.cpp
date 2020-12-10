// Time com: O(m+n)-> bfs of graph but in tree we know that m=no. of nodes = n-1(edges -1)
// therefore O(m+n) == O(n-1 + n) == O(n) 🔥🤩


// space com: O(n) ==  map for parent and node->n  and visited set-> (n) and queue == upperbound of no.of nodes 
// So overall it is O(n) only👌
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left =right = NULL;
    }

};


class solver
{
private:
   unordered_map<Node*, Node*> m;
    set<Node*> s;
    queue<Node*> q;
       
        Node* findNode(Node* root, int target){
        if(!root) return NULL;
        
        // If target found then return the node 
        if(root->data == target) return root;
        
        // check in left and right
        Node* l = findNode(root->left,target);
        if(l) return l;
        
        Node* r = findNode(root->right,target);
        if(r) return r;
        
        // if target not found 
        return NULL;
        
    }
    
    void attachParent(Node* root,Node* parent){
        
        if(!root) return;
        
        m[root] = parent;
        
        attachParent(root->left,root);
        
        attachParent(root->right,root);
    }
    
    
    void nextLevel(){
        Node* temp;
        while(1){
            
            temp = q.front();
            q.pop();
            
            if(!temp){
                if(q.size() != 0)
                    q.push(NULL);
                     
              return;
            }
        
        
        // If temp exists push its left,right and parent to queue and make them visited
        
        // Left push if exist and not visited
        if(temp->left && s.find(temp->left) == s.end()){
            
            q.push(temp->left);
            s.insert(temp->left);
        }
        
         
        // Right push if exist and not visited
        if(temp->right && s.find(temp->right) == s.end()){
            
            q.push(temp->right);
            s.insert(temp->right);
        }

        // parent push if exist and not visited
        if(m[temp] && s.find(m[temp]) == s.end()){
            
            q.push(m[temp]);
            s.insert(m[temp]);
        }
        
            
    }//While end
    
}

public:
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {   
        vector<int> ans;
        if(!root) return ans;

        // finding the target node in the tree
        Node * temp = findNode(root,target);
        
        if(!temp) return ans;

        // To store node and its parent
        // passing root element and its parent ie NULL
        attachParent(root,NULL);
      
        
        int level =0;
        
        // Push the target element first and NULL to differentiate levels
        q.push(temp);
        q.push(NULL);
        
        // Make target element visited 
        s.insert(temp);
        
        
        // LevelOrder
        
        while(!q.empty()){
            // if we reach the required level push element in ans from queue
            if(level == k){
                    while(!q.empty()){
                    Node * curr = q.front();
                    q.pop();
                    if(curr)
                        // cout<<"Vector Node:" <<curr->data<<" ";
                        ans.push_back(curr->data);
                        
                    }
                    sort(ans.begin(),ans.end());
                    return ans;
            }
            // if not reach the level then check for next level and push the 
            // left, right and parent of that level
            level++;
            nextLevel();
        }
        // cout<<"size: "<< ans.size();
        return ans;
    }
};