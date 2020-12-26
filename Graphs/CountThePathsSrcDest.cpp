#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> g[], vector<bool> vis, int& count,int src,int dest){
    
    if(src == dest){
        count++;
        return;
    }
    vis[src] = true;
    for(auto node: g[src]){
        if(!vis[node]){
            dfs(g,vis,count,node,dest);
        }
    }
    
    // make current node vis = false to ensure this node will be included in
    // some other path 
    vis[src]= false;
}
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int v,e;
	    cin>>v>>e;
	    vector<int> adj[v];
	    for(int i=0;i<e; i++){
	        int u,v;
	        cin>>u>>v;
	        adj[u].push_back(v);
	    }
	    int s,d;
	    cin>>s>>d;
        
	    int count=0;
	    
	    vector<bool> vis(v,false);
	    dfs(adj,vis,count,s,d);
	    
	    
	    cout<<count<<endl;
	}
	return 0;
}