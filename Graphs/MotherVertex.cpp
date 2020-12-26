// code snippet
#include<bits/stdc++.h>
using namespace std;

void av()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void dfs(vector<int> g[], int start,vector<bool>& vis, int V){
    
    vis[start] = true;
    
    // check for Neighbors
    for(auto neigh: g[start]){
        
        // if neigh is not visited call dfs 
        if(!vis[neigh]){
            dfs(g,neigh,vis,V);
        }
    }
}
int findMother(int V, vector<int> g[]) 
{ 
    	int lastDfsNode;
    // 	Initially all nodes are not visited
    	vector<bool> vis(V,false);
    	
    // 	call dfs for each node and store the last_dfs node
    
    for(int i=0;i<V; i++){
        
        if(!vis[i]){
            dfs(g,i,vis,V);
            lastDfsNode = i;
        }
    }
    // Again make the all not visited
    fill(vis.begin(),vis.end(),false);
    
    // Applying dfs from node "lastDfsNode"
    dfs(g,lastDfsNode, vis, V);
    
    // Check for each node whether vis is true or not
    for(int i=0;i<V;i++){
        
        // If any one node is false then lastDfsNode is not Mother vertex
        if(!vis[i])
            return -1;
    }
    // If loop ends means all nodes are visited means we got out MV
    return lastDfsNode;
    	
}

int main(){

    av();
    int V,E;
    cin>>V>>E;
    // Adjacency list
    vector<int> adj[V];

    int u,v;
    while(E--){
        cin>>u>>v;
        adj[u].push_back(v);
    }


    cout<<"Mother Vertex: "<<findMother(V,adj)<<endl;
}