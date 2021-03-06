#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> g[],int n, bool vis[],int start){

    vis[start] = true;
    cout<<start<<"->";

    for(auto node: g[start]){

        if(!vis[node]){
            DFS(g,n,vis,node);
        }
    }
}

void dfs(vector<int> g[], int v){
    
    bool vis[v];
    for(int i=0;i<v; i++)
        vis[i] = false; 

    DFS(g,v,vis,0);
}
int main(){

    int v,e;
    cin>>v>>e;
    // Adjacency list
    vector<int> adj[v];

    for(int i=0;i<e; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    
    dfs(adj, v);
}