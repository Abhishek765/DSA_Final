// code snippet
#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> g[], int n, bool vis[], int start, bool anc[]){
    
    vis[start] = true;
    anc[start] = true;
    
    for(auto node : g[start])
    {
        if(!vis[node]){
            if(dfs(g,n,vis,node,anc))
            return true;
        }
        else if(anc[node]){
            return true;
        }
    }
    anc[start] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    bool vis[V],anc[V];
    for(int i=0;i<V; i++)
        vis[i] = false;
        
    for(int i=0; i<V; i++){
        if(!vis[i])
            if(dfs(adj,V,vis, i, anc))
                return true;
    }
    
    return false;
    
}