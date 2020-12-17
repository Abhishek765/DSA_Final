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
// Undirected graph 
void addEdge(vector<int> adj[],int u, int v) 
{ 
    adj[u].push_back(v); // Add w to v’s list. 
    adj[v].push_back(u); // Add v to w’s list. 
} 

bool isCyclicUsingDFS(vector<int> g[], int v, vector<bool>& vis,int start,int parent){

    vis[start] = true;

    // neighbours
    for(auto node: g[start]){
        // If node is not visited
        if(!vis[node]){
            // If inner subgraph returns true i.e cycle then return true
            if(isCyclicUsingDFS(g,v,vis,node,start))
                return true;
        }
        // traversing a node which is visited and not a parent
        else if(node != parent){
            return true;
        }

    }

    return false;
}
bool isTree(vector<int> adj[],int v){
    
    vector<bool> vis(v, false);
    
    // If cycledetected not a tree
    if (isCyclicUsingDFS(adj,v,vis,0,-1))
        return false;

    for(int i=0;i<v;i++){
        // if either of the node is not visited means graph is not connected
        if(!vis[i])
            return false;
    }
    return true;
}
int main(){

    av();
    // Adjacency list
    vector<int> adj[5];
    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,3,4);

    (isTree(adj,5)) ? cout<<"Tree\n" : cout<<"Not a tree\n";     
    
}