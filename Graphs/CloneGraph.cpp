// TODO: Needs Correction
// ! Time when BFS used O(V + E)
// ! Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;

void av()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void dfs(Node* u, set<Node*>& vis, map<Node*,Node*>& mp){
        
//         mark the curr_node visited
        vis.insert(u);
        
//         make the copy node of u and set the same value as u
        Node* u_copy = new Node(u->val);
        
//         insert u and u_copy in map
        mp.insert({u,u_copy});
        
//         traverse through neighbours which are not visited      
        for(auto v: u->neighbors){
            
//             if v is not traversed
            if(vis.find(v) == vis.end()){
                
                // apply the dfs
                dfs(v,vis,mp);
            }
        }       
    }
    
    void addEdges( map<Node*,Node*>& mp){
        
            // iterate through map
        for(auto u: mp){
            
            // iterate through neighbours
            
            for(auto v: u.first->neighbors){
                
                // cout<<"V: "<<v->val<<" ";
//                 add the neighbors to copy node neighbors vector                
                u.second->neighbors.push_back(v);
                
            }
        }
    }
    Node* cloneGraph(Node* node) {
        
        if(node ==NULL)
            return NULL;
//         Steps 
//               1. Apply the dfs and make the node's copy and map the node and copy_node
//               2. Making of links in copy nodes using map 
        
//        1. dfs
//         set for marking visited for a node since there address are different we can't use simple visited arr
        set<Node*> vis;
        
//         Map for mapping node and node_copy
        map<Node*,Node*> mp;
        
//         first make the copy of root node , make it visted and insert it in map
        Node* copy_node = new Node(node->val);
        
        vis.insert(copy_node);
        mp.insert({node,copy_node});
        
        for(auto start : node->neighbors){
             if(vis.find(start) == vis.end()){
                
                // apply the dfs
                dfs(start,vis,mp);
            }
        }
        
        
//      2. Linking Process
        addEdges(mp);
        
        // mp[node] contains the reference of copy_node
        
        return mp[node];
    }
};