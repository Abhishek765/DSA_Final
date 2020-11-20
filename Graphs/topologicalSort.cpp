// code snippet
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[], int v,bool vis[], int start,stack<int>& s){
    vis[start] = true;
    
    for(auto node: g[start]){
        
        if(!vis[node]){
            dfs(g,v,vis,node,s);
        }
    }
    
    s.push(start);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int> s;
    
    vector<int> ans;
    bool vis[V];
    
    for(int i=0; i<V; i++){
        vis[i] = false;
    }
    
    for(int i=0;i<V; i++){
        if(!vis[i]){
            dfs(adj,V,vis,i,s);
        }
    }
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
    
}